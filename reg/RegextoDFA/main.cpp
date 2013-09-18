#include "DFA.h"


// Ö÷º¯Êý
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



