#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

//--------------------------------��ջ����---------------------------------------//
//---------------------------����ģ������ʵ�ֶ�ջ����----------------------------//
//-----------------------------Ӧ���ڲ�ͬ�±�������------------------------------//
#define NULL 0

template<class T>
class LinkedStack;
//////////////////////////////////////////////////////////
//��ջ���ṹLinkSNode�Ķ���
//////////////////////////////////////////////////////////
template <class T> 
class LinkSNode
{   
	friend class LinkedStack<T>;
	//������
	T data;
	//ָ����
	LinkSNode<T>* link;
	//��㹹�캯��,ֻ��ָ���ʼ��
    LinkSNode(LinkSNode<T>* ptr=NULL)
	{
		//�ò�����ʼ��
		link=ptr;
	};
	//��㹹�캯��,�����ݺ�ָ���ʼ��
	LinkSNode(const T& item,LinkSNode<T>* ptr=NULL)
	{
		//��ʼ������
		data=item;
		//��ʼ��ָ��
		link=ptr;
	};	
};
//////////////////////////////////////////LinkSNode�ṹ����

//////////////////////////////////////////////////////////
//��ջ��LinkedStack�������Ͷ���
//��ջ�е������ǲ�������ͷ����
//////////////////////////////////////////////////////////
template<class T>
class LinkedStack //:Stack
{
public:
	//���캯�����õ�һ����ջ
    LinkedStack()
	{top=NULL;};
	//��������
	~LinkedStack()
	{makeEmpty();};
	//��ջ��������x��ΪԪ��ֵѹ��ջ
	void Push(const T& x);
	//��ջ��������x���ص�����Ԫ��
	T Pop(void);
	//��ȡջ��Ԫ�أ����뵽x��ȥ
	T getTop(void);
	//�ж϶�ջ�Ƿ�Ϊ��
	bool IsEmpty(void)const
	{return (top==NULL)?true:false;};
	//�õ���ջ��Ԫ�صĸ���
	int getSize(void)const;
	//��ն�ջ�����е�����
	void makeEmpty(void);
private:
	//ջ��ָ�룬������ͷ��ָ��
	LinkSNode<T>* top;
};
/////////////////////////////////////LinkedStack����������

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
};
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
};
////////////////////////////////////////////Push()��������

//////////////////////////////////////////////////////////
//Pop()����  ��ջ��������x���ص�����Ԫ��
//////////////////////////////////////////////////////////
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
};
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
};
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
};
/////////////////////////////////////////getSize()��������

#endif