#ifndef DFA_H
#define DFA_H
#include "TTable.h"
#include "Adjtable.h"
#include "LinkedStack.h"
// ����DFA�Ĺ�����
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
	void check();                        //�ж�������ַ����Ƿ񱻽���
private:
	char *exp;
	char *post;
	char *edge;
	char WordBuffer[1024];            //�洢�����ַ���������
	int edgeNumber;
	int **DStates;
	int **Dtran;
	int **Move;                       //��СDFA״̬ת����
	int *AcceptStates;
	int DStatesNumber;
	int DtranNumber;
	int NFAStatesNumber;
	int DFAStatesNumber;
	int FinalState;                 //��¼��̬
	int r,l;
	AdjacentTable *NFATable;
	TransitionTable *DFATable;
	int Precedence(char symbol);
	int CompArray(int *t1, int *t2);
	int MinimizeDFAStates(int **Dtran, int *AcceptStates, int DtranNumber, int edgeNumber);
};
#endif