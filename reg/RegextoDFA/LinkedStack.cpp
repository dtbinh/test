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
//makeEmpty()��Ա���� �Ѷ�ջ���е�Ԫ����ռ�Ľ���ͷ�
//////////////////////////////////////////////////////////
template<class T>
void LinkedStack<T>::makeEmpty(void)
{
	if(top!=NULL)
	{
		//ָ���ɾ����ָ����
		LinkSNode<T>* del;
		//���ɾ��ÿ����ջ�Ľ��
		while(top!=NULL)
		{
			del=top;
			top=top->link;
			delete del;
		};
	}
}
///////////////////////////////////////makeEmpty()��������

//////////////////////////////////////////////////////////
//Push()����  ��ջ��������x��ΪԪ��ֵѹ��ջ
//////////////////////////////////////////////////////////
template<class T>
void LinkedStack<T>::Push(const T& x)
{
	//��xΪֵ�½�һ�����,
	//�øý���ָ�����ǲ���֮ǰ��top
	LinkSNode<T>* newNode=new LinkSNode<T>(x,top);
	if(newNode==NULL)
	{
		cerr<<"��ջ�½���ڴ����ʧ��!"<<endl;
		exit(1);
	}
	//�õ��µ�top
	top=newNode;
}
////////////////////////////////////////////Push()��������

//////////////////////////////////////////////////////////
//Pop()����  ��ջ��������x���ص�����Ԫ��
/////////////////////////////////////////////////////////
template<class T>
T LinkedStack<T>::Pop(void)
{
	if(top==NULL)
	{
		cout<<"��ǰ��ջΪ�գ�û��Ԫ�ؿ��Ե���!"<<endl;
		exit(1);
	}
	//ɾ�������Ľ��
	LinkSNode<T>* del=top;
	//ջ�������ƶ�һ��
	top=top->link;
	T x=del->data;
	delete del;
	
	return x;
}
/////////////////////////////////////////////Pop()��������

//////////////////////////////////////////////////////////
//getTop()����  ��ȡջ��Ԫ�أ����뵽x��ȥ
//////////////////////////////////////////////////////////
template<class T>
T LinkedStack<T>::getTop(void)
{
	if(top==NULL)
	{
		cout<<"��ǰ��ջΪ��!"<<endl;
		exit(1);
	};
	
	return top->data;
}
//////////////////////////////////////////getTop()��������

//////////////////////////////////////////////////////////
//getSize()����  �õ���ջ��Ԫ�صĸ���
//////////////////////////////////////////////////////////
template<class T>
int LinkedStack<T>::getSize()const
{
	if(top==NULL)
		return 0;
	//�α�ָ��
	LinkSNode<T>* ptr=top;
	//������
	int count=0;
	//ͳ��Ԫ�صĸ���
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	};
	
	return count;
}
/////////////////////////////////////////getSize()��������
*/