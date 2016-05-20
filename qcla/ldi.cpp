#include "ldi.h"

using namespace std;

extern void analyze_ldi(string expression, string &value);


void LDI:: setLdi(string expression)
{
	string value_temp;
	setLdiExpression(expression);
	analyze_ldi(expression, value_temp);
	setValue(value_temp);
}

vector<Location> LDI:: getLdi()
{
	return ldi;
}
