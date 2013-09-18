#include "TTable.h"

// ���캯��
TransitionTable::TransitionTable(int rowNum, int colNum)
{
	rowNumber = rowNum;
	colNumber = colNum;
	matrix = (int**)(new int*[rowNumber]);
	for (int i=0; i<rowNumber; i++)
	{
		matrix[i] = new int[colNumber];
	}
}
// ��������
TransitionTable::~TransitionTable()
{
	Clear();
}
// ����Ԫ�ص�ֵ
void TransitionTable::SetValue(int i, int j, int value)
{
	matrix[i][j] = value;
}
// ��ȡԪ�ص�ֵ
int TransitionTable::GetValue(int i, int j)
{
	return matrix[i][j];
}
// ״̬ת�ƺ���
int TransitionTable::Transit(int current, char input, char *edge)
{
	for (int i=0; edge[i]!= '\0'; i++)
	{
		if (input == edge[i])
		{
			return matrix[current][i];
		}
	}
	return -1;
}
// ���ת�ƾ���
void TransitionTable::Clear(void)
{
	for (int i=0; i<rowNumber; i++)
	{
		delete [] matrix[i];
	}
	delete matrix;
}

/////////////////////////////////////////////////