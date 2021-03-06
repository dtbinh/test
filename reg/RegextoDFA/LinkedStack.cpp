/*#include "LinkedStack.h"




template<class T>
LinkedStack<T>::LinkedStack()
{
	top=NULL;
}

template<class T>
LinkedStack<T>::~LinkedStack()
{
	makeEmpty();
}

//////////////////////////////////////////////////////////
//makeEmpty()成员函数 把堆栈所有的元素所占的结点释放
//////////////////////////////////////////////////////////
template<class T>
void LinkedStack<T>::makeEmpty(void)
{
	if(top!=NULL)
	{
		//指向待删除的指针结点
		LinkSNode<T>* del;
		//逐个删除每个链栈的结点
		while(top!=NULL)
		{
			del=top;
			top=top->link;
			delete del;
		};
	}
}
///////////////////////////////////////makeEmpty()函数结束

//////////////////////////////////////////////////////////
//Push()函数  进栈操作，把x作为元素值压入栈
//////////////////////////////////////////////////////////
template<class T>
void LinkedStack<T>::Push(const T& x)
{
	//以x为值新建一个结点,
	//让该结点的指针域是插入之前的top
	LinkSNode<T>* newNode=new LinkSNode<T>(x,top);
	if(newNode==NULL)
	{
		cerr<<"堆栈新结点内存分配失败!"<<endl;
		exit(1);
	}
	//得到新的top
	top=newNode;
}
////////////////////////////////////////////Push()函数结束

//////////////////////////////////////////////////////////
//Pop()函数  出栈操作，以x返回弹出的元素
/////////////////////////////////////////////////////////
template<class T>
T LinkedStack<T>::Pop(void)
{
	if(top==NULL)
	{
		cout<<"当前堆栈为空，没有元素可以弹出!"<<endl;
		exit(1);
	}
	//删除弹出的结点
	LinkSNode<T>* del=top;
	//栈顶向下移动一格
	top=top->link;
	T x=del->data;
	delete del;
	
	return x;
}
/////////////////////////////////////////////Pop()函数结束

//////////////////////////////////////////////////////////
//getTop()函数  读取栈顶元素，读入到x中去
//////////////////////////////////////////////////////////
template<class T>
T LinkedStack<T>::getTop(void)
{
	if(top==NULL)
	{
		cout<<"当前堆栈为空!"<<endl;
		exit(1);
	};
	
	return top->data;
}
//////////////////////////////////////////getTop()函数结束

//////////////////////////////////////////////////////////
//getSize()函数  得到堆栈中元素的个数
//////////////////////////////////////////////////////////
template<class T>
int LinkedStack<T>::getSize()const
{
	if(top==NULL)
		return 0;
	//游标指针
	LinkSNode<T>* ptr=top;
	//计数器
	int count=0;
	//统计元素的个数
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	};
	
	return count;
}
/////////////////////////////////////////getSize()函数结束
*/