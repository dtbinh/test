#include "DFA.h"
#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>



// 构造函数
DFA::DFA()
{
	exp = new char[128];
	post = new char[128];
	edge = new char[128];
    edgeNumber = 0;
	NFAStatesNumber = 0;
	DFAStatesNumber = 0;
	DStatesNumber = 0;
	DtranNumber = 0;
	NFATable = new AdjacentTable();
}
// 析构函数
DFA::~DFA()
{
	delete [] exp;
	delete [] post;
	delete [] edge;
	delete [] AcceptStates;
	NFATable->Clear();
	DFATable->Clear();
}
// 获取输入
void DFA::GetRegExp()
{
	cout << "请输入正则表达式(Regular Expression):" << endl;
	cin >> exp;
	for (int i=0; exp[i]!='\0'; i++)
	{
		if (exp[i] == '$')
		{
			cout << "\n字符'$'已经被程序禁用！" << endl;
			getch();
			exit(1);
		}
	}
}
// 加入cat-node作为连结点标志
void DFA::InsertCatNode()
{
	int i = 0, j, len = strlen(exp);
	while (exp[i+1] != '\0')
	{
		if (((exp[i] != '(' && exp[i] != '.' && exp[i] != '|') 
			|| exp[i] == ')' 
			|| exp[i] == '*')
			&& (exp[i+1] != ')' && exp[i+1] != '.' && exp[i+1] != '|' && exp[i+1] != '*'))
		{
			for (j=len; j>i+1; j--)
			{
				exp[j] = exp[j-1];
			}
			exp[i+1] = '.';
			len++;
			exp[len] = '\0';
			i++;
		}
		i++;
	}
	cout << "\n给正则表达式添加与运算符号:\n"
		 << exp << "\n";
}
// 定义运算符的优先级
int DFA::Precedence(char symbol)
{
	int priority;
	switch (symbol)
	{
	case '|': priority = 1; break;
	case '.': priority = 2; break;
	case '*': priority = 3; break;
	default:  priority = 0; break;
	}
	return priority;
}
// 将正则式转为逆波兰式
void DFA::RegExpToPost()
{
	int i = 0, j = 0;
	char ch, cl;
	strcpy(post, "\0");
	LinkedStack<char> *ls = new LinkedStack<char>();
	ls->makeEmpty();
	ls->Push('#');
	ch = exp[i];
	while (ch != '\0')
	{
		if (ch == '(')
		{
			ls->Push(ch);
			ch = exp[++i];
		}
		else if (ch == ')')
		{
			while (ls->getTop() != '(')
			{
				post[j++] = ls->Pop();
			}
            ls->Pop();
			ch = exp[++i];
		}
		else if ((ch == '|') || (ch == '*') || (ch == '.'))
		{
	    	cl = ls->getTop();
		   	while (Precedence(cl) >= Precedence(ch))
			{
		    	post[j++] = cl;
		    	ls->Pop();
		    	cl = ls->getTop();
			}
			ls->Push(ch);
			ch = exp[++i];
		}
		else
		{
			post[j++] = ch;
			ch = exp[++i];
		}
	}
	ch = ls->Pop();
	while ((ch == '|') || (ch == '*') || (ch == '.'))
	{
		post[j++] = ch;
		ch = ls->Pop();
	}
	post[j] = '\0';
	ls->makeEmpty();
}
// 扫描逆波兰式中除运算符以外的字符的数目
void DFA::GetEdgeNumber()
{
	int i = 0, j;
	edgeNumber = 0;
	while (post[i] != '\0')
	{
		if (post[i] == '.' || post[i] == '|' || post[i] == '*')
		{
			i++;
			continue;
		}
		for (j=0; j<edgeNumber; j++)
		{
			if (post[i] == edge[j])
			{
				break;
			}
		}
		if (j == edgeNumber)
		{
			edge[edgeNumber] = post[i];
			edgeNumber++;
		}
		i++;
	}
	edge[edgeNumber] = '\0';
	cout << "\n输出从正则表达式获取的字符集:\n";
	for (i=0; i<edgeNumber; i++)
	{
		cout << edge[i] << ' ';
	}
	cout << "\n字符个数: " << edgeNumber<< endl;
}
// 用Thompson构造法构造NFA
void DFA::ThompsonConstruction()
{
	int i, j;
	char ch;
	int s1, s2;
	LinkedStack<int> *states = new LinkedStack<int>();
	states->makeEmpty();
	if (strlen(post) < 1)
	{
		cout << "No Valid Regular Expression Found!" << endl;
		getch();
		exit(1);
	}
	NFATable->SetValue(0, 0);
	i = 1;
	j = 0;
	ch = post[j];
    while (ch != '\0')
	{
		if (ch == '.')
		{
			s2 = states->Pop();
			int temp1 = states->Pop();
			int temp2 = states->Pop();
			s1 = states->Pop();
			NFATable->InsertEdgeByValue(temp2, temp1, '$');
			states->Push(s1);
			states->Push(s2);
		}
		else if (ch == '|')
		{
			s2 = states->Pop();
			int temp1 = states->Pop();
			int temp2 = states->Pop();
			s1 = states->Pop();
			NFATable->InsertVertex(i);
			NFATable->InsertVertex(i+1);
			NFATable->InsertEdgeByValue(i, s1, '$');
			NFATable->InsertEdgeByValue(i, temp1, '$');
			NFATable->InsertEdgeByValue(temp2, i+1, '$');
			NFATable->InsertEdgeByValue(s2, i+1, '$');
			s1 = i;
			s2 = i+1;
			states->Push(s1);
			states->Push(s2);
			i += 2;
		}
		else if (ch == '*')
		{
			s2 = states->Pop();
			s1 = states->Pop();
			NFATable->InsertVertex(i);
			NFATable->InsertVertex(i+1);
			NFATable->InsertEdgeByValue(i, i+1, '$');
			NFATable->InsertEdgeByValue(s2, s1, '$');
			NFATable->InsertEdgeByValue(i, s1, '$');
			NFATable->InsertEdgeByValue(s2, i+1, '$');
			s1 = i;
			s2 = i+1;
			states->Push(s1);
			states->Push(s2);
			i += 2;
		}
		else
		{
			NFATable->InsertVertex(i);
			NFATable->InsertVertex(i+1);
			NFATable->InsertEdgeByValue(i, i+1, ch);
			s1 = i;
			s2 = i+1;
			states->Push(s1);
			states->Push(s2);
			i += 2;
		}
		j++;
		ch = post[j];
	}
	s2 = states->Pop();
	s1 = states->Pop();
	NFATable->InsertEdgeByValue(0, s1, '$');
	if (! states->IsEmpty())
	{
		cout << "Some error in your input string!" << endl;
		getch();
		exit(1);
	}
	NFAStatesNumber = s2 + 1;
}
// 比较两个一维数组是否含有完全相同的元素
int DFA::CompArray(int *t1, int *t2)
{
	int i = 0, j = 0, len1, len2;
	while (t1[i] != -1)
	{
		i++;
	}
	len1 = i;
	while (t2[j] != -1)
	{
		j++;
	}
	len2 = j;
	if (len1 != len2)
	{
		return 0;
	}
	for (i=0; i<len1; i++)
	{
		for (j=0; j<len2; j++)
		{
			if (t1[i] == t2[j])
			{
				break;
			}
		}
		if (j == len2)
		{
			return 0;
		}
	}
	return 1;
}
// 最小化Dtran表
int DFA::MinimizeDFAStates(int **Dtran, int *AcceptStates, int DtranNumber, int edgeNumber)
{
	int h, i, j, k, l;
	for (i=0; i<DtranNumber-1; i++)
	{
		for (j=i+1; j<DtranNumber; j++)
		{
			if (AcceptStates[i] == AcceptStates[j])
			{
				for (k=0; k<edgeNumber; k++)
				{
					if (Dtran[i][k] != Dtran[j][k])
					{
						break;
					}
				}
				if (k == edgeNumber)
				{
					for (l=j; l<DtranNumber-1; l++)
					{
						for (k=0; k<edgeNumber; k++)
						{
							Dtran[l][k] = Dtran[l+1][k];
						}
						AcceptStates[l] = AcceptStates[l+1];
					}
					for (l=0; l<DtranNumber-1; l++)
					{
						for (k=0; k<edgeNumber; k++)
						{
							if (Dtran[l][k] == j)
							{
								Dtran[l][k] = i;
							}
						}
					}
					for (h=j; h<DtranNumber; h++)
					{
						for (l=0; l<DtranNumber-1; l++)
						{
							for (k=0; k<edgeNumber; k++)
							{
								if (Dtran[l][k] == h+1)
								{
									Dtran[l][k] = h;
								}
							}
						}
					}
					DtranNumber--;
					j--;
				}
			}
		}
	}
	return DtranNumber;
}
// 用子集构造法构造DFA
void DFA::SubsetConstruction()
{
	int i, j, k;
	DStatesNumber = 0;
	DtranNumber = 0;
	// 输出NFA状态表
	cout << "\n输出含Epslion的NFA的状态表(其中$表示Epslion):\n\n";
    NFATable->OutputNFA();
	cout << endl;
	// 初始化DStates和Dtran两个构造表及AcceptStates数组
	DStates = (int**)(new int*[NFAStatesNumber+1]);
	for (i=0; i<NFAStatesNumber+1; i++)
	{
		DStates[i] = new int[NFAStatesNumber+1];
	}
	Dtran = (int**)(new int*[NFAStatesNumber+1]);
	for (i=0; i<NFAStatesNumber+1; i++)
	{
		Dtran[i] = new int[edgeNumber+1];
	}
	for (i=0; i<NFAStatesNumber+1; i++)
	{
		for (j=0; j<edgeNumber+1; j++)
		{
			Dtran[i][j] = -1;
		}
	}
	AcceptStates = new int[NFAStatesNumber+1];
	for (i=0; i<NFAStatesNumber+1; i++)
	{
		AcceptStates[i] = 0;
	}
	// 调用闭包函数和移动函数构造DStates和Dtran两个表
    int *T = new int[NFAStatesNumber+1];
	int *temp = new int[NFAStatesNumber+1];
	T[0] = 0;
	T[1] = -1;
	T = NFATable->Closure(T);
	DStates[DStatesNumber] = T;
	DStatesNumber++;
	k = 0;
	while (k < DStatesNumber)
	{
		for (i=0; edge[i]!='\0'; i++)
		{
			temp = NFATable->Closure(NFATable->Move(T, edge[i]));
			if (temp[0] != -1)
			{
				for (j=0; j<DStatesNumber; j++)
				{
					if (CompArray(temp, DStates[j]) == 1)
					{
						Dtran[k][i] = j;
						break;
					}
				}
				if (j == DStatesNumber)
				{
					DStates[DStatesNumber] = temp;
					Dtran[k][i] = DStatesNumber;
					DStatesNumber++;
				}
			}
		}
		k++;
		T = DStates[k];
	}
	DtranNumber = k;
	for (i=0; i<DStatesNumber; i++)
	{
		for (j=0; DStates[i][j]!= -1; j++)
		{
			if (DStates[i][j] == NFAStatesNumber - 1)
			{
				AcceptStates[i] = 1;
				break;
			}
		}
	}
	// 输出DStates表项
	cout << "\n输出Epsilon-closure集合:\n\n";
	for (i=0; i<DStatesNumber; i++)
	{
		cout << "状态集合" << i <<":  ";
		j = 0;
		while (DStates[i][j] != -1)
		{
			cout << DStates[i][j] << " ";
			j++;
		}
		cout << endl;
	}
	// 输出Dtran表项
	cout << "\n输出DFA状态转换表:\n\n状态 ";
	for (j=0; j<edgeNumber; j++)
	{
		cout << "    " << edge[j];
	}
	cout<<endl;
	for (i=0; i<DtranNumber; i++)
	{
		if (i < 10)  cout << "   " << i << " ";
		else if (i < 100)  cout << "  " << i << " ";
		else if (i < 1000)  cout << " " << i << " ";
		else  cout << i << " ";
		for (j=0; j<edgeNumber; j++)
		{
			if (Dtran[i][j] < 0)  cout << "     ";
			else if (Dtran[i][j] < 10)  cout << "    " << Dtran[i][j];
			else if (Dtran[i][j] < 100)  cout << "   " << Dtran[i][j];
			else if (Dtran[i][j] < 1000)  cout << "  " << Dtran[i][j];
			else  cout << " " << Dtran[i][j];
		}
		cout << endl;
	}
	// 反复检测Dtran表中是否能化简，能则继续化简
	int DtranNumberAfterMinimization = MinimizeDFAStates(Dtran, AcceptStates, DtranNumber, edgeNumber);
	while (DtranNumberAfterMinimization != DtranNumber)
	{
		DtranNumber = DtranNumberAfterMinimization;
		DtranNumberAfterMinimization = MinimizeDFAStates(Dtran, AcceptStates, DtranNumber, edgeNumber);
	}
	// 将Dtran表的内容拷贝到DFA表
	DFATable = new TransitionTable(DtranNumber, edgeNumber);
	for (i=0; i<DtranNumber; i++)
	{
		for (j=0; j<edgeNumber; j++)
		{
			DFATable->SetValue(i, j, Dtran[i][j]);
		}
	}
	// 输出DFA状态表
	cout << "\n输出最小化DFA后状态转换表:\n\n状态 ";
	for (j=0; j<edgeNumber; j++)
	{
		cout << "    " << edge[j];
	}
	cout<<endl;
	for (i=0; i<DtranNumber; i++)
	{
		if (i < 10)  cout << "   " << i << " ";
		else if (i < 100)  cout << "  " << i << " ";
		else if (i < 1000)  cout << " " << i << " ";
		else  cout << i << " ";
		for (j=0; j<edgeNumber; j++)
		{
			if (DFATable->GetValue(i, j) < 0)  cout << "     ";
			else if (DFATable->GetValue(i, j) < 10)  cout << "    " << DFATable->GetValue(i, j);
			else if (DFATable->GetValue(i, j) < 100)  cout << "   " << DFATable->GetValue(i, j);
			else if (DFATable->GetValue(i, j) < 1000)  cout << "  " << DFATable->GetValue(i, j);
			else  cout << " " << DFATable->GetValue(i, j);
		}
		cout << endl;
	}
	FinalState=DtranNumber-1;
	Move = (int**)(new int*[DtranNumber]);
	for(j=0;j<DtranNumber;j++)   
		Move[j] = new int[edgeNumber+1]; 
	for (j=0;j<DtranNumber;j++)
		for (int k=0;k<edgeNumber+1;k++)
		{   
			if (k==0)
			{
				Move[j][k] = j;
			}
			else
			    Move[j][k]=DFATable->GetValue(j,k-1);
		}
		r = DtranNumber;
		l = edgeNumber+1;
	// 析构DStates和Dtran表以及AcceptStates数组
	for (i=0; i<NFAStatesNumber+1; i++)
	{
		delete [] DStates[i];
		delete [] Dtran[i];
	}
	delete [] DStates;
	delete [] Dtran;
}
//判断字符串是否被自动机接受
void DFA::check()
{   
	printf("请输入要被该DFA判断的字符串:\n");
	fflush(stdin);
	int i=0;
	while(WordBuffer[i-1]!='\n')
	{
		WordBuffer[i]=getchar();
		i++;
	}
	int row=0,line=0;
	int s=Move[row][line];
	for(int j=0;j<i-1;j++)
	{	
		line=0;	
		for (int k=0;k<edgeNumber;k++)
		{
			if(WordBuffer[j]==edge[k])
			{
				line=line+k+1;
				s=Move[row][line];
				break;
			}
		}
		for(int t=0;t<r;t++)
			if(s==Move[t][0])
			{
				row=t;
				break;
			}
			s=Move[row][0];		
	} 
	for (i=0; i<r; i++)
	{
		delete [] Move[i];
	}
	delete [] Move;
	if(s==FinalState)
		cout<<"\nDFA accept!\n";
	else
		cout<<"\nDFA can't accept!\n";
}
/////////////////////////////////////////////////