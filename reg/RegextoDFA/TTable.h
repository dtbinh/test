#ifndef TTABLE20090919_H
#define TTABLE20090919_H



// 定义转移矩阵类
class TransitionTable
{
public:
	TransitionTable(int rowNum, int colNum);
	~TransitionTable();
	void SetValue(int i, int j, int value);
	int GetValue(int i, int j);
	int Transit(int current, char input, char *edge);
	void Clear(void);
private:
	int **matrix;
	int rowNumber;
	int colNumber;
};
#endif