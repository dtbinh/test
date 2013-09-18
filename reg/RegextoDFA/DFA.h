#ifndef DFA_H
#define DFA_H
#include "TTable.h"
#include "Adjtable.h"
#include "LinkedStack.h"
// 定义DFA的构造类
class DFA
{
public:
	DFA();
	~DFA();
	void GetRegExp();
	void InsertCatNode();
	void RegExpToPost();
	void GetEdgeNumber();
	void ThompsonConstruction();
	void SubsetConstruction();
	void check();                        //判断输入的字符串是否被接受
private:
	char *exp;
	char *post;
	char *edge;
	char WordBuffer[1024];            //存储输入字符串的数组
	int edgeNumber;
	int **DStates;
	int **Dtran;
	int **Move;                       //最小DFA状态转换表
	int *AcceptStates;
	int DStatesNumber;
	int DtranNumber;
	int NFAStatesNumber;
	int DFAStatesNumber;
	int FinalState;                 //记录终态
	int r,l;
	AdjacentTable *NFATable;
	TransitionTable *DFATable;
	int Precedence(char symbol);
	int CompArray(int *t1, int *t2);
	int MinimizeDFAStates(int **Dtran, int *AcceptStates, int DtranNumber, int edgeNumber);
};
#endif