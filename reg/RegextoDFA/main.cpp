#include "DFA.h"


// ������
void main()
{
	DFA dfa;
	dfa.GetRegExp();
	dfa.InsertCatNode();
	dfa.RegExpToPost();
	dfa.GetEdgeNumber();
	dfa.ThompsonConstruction();
	dfa.SubsetConstruction();
	dfa.check();
}



