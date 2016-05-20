#include <iostream>
#include <stdlib.h>
#include "eldi.h"

extern void analyze_formula(string formula, string &interval, string &eldi_formula);
extern void analyze_eldi(string expression, vector<string>& sequence);
extern void analyze_interval(string interval, string &lowerB, string &upperB);

void ELDI::setEldi(string formula)
{
	string interval_temp;
	string eldi_expression_temp;
	
	analyze_formula(formula, interval_temp, eldi_expression_temp);
	setInterval(interval_temp);
	setEldiExpression(eldi_expression_temp);
	
	cout << formula << endl;
	cout << getInterval() << endl;
	cout << getEldiExpression() << endl;
	
	analyze_eldi(getEldiExpression(), ldi_sequence);
	analyze_interval(interval, lowerB, upperB);
	
	vector<string>::iterator eldi_it;
	for(eldi_it = ldi_sequence.begin(); eldi_it != ldi_sequence.end(); eldi_it++)
	{
		LDI ldi;
		string temp = *eldi_it;
		ldi.setLdi(temp);
	}
	
}

void ELDI:: setLB(string lb)
{
	lower_bound = atoi(lb.c_str());
}

void ELDI:: setUB(string ub)
{
	upper_bound = atoi(ub.c_str());
}

vector<string> ELDI::get_ldi_sequence()
{
	return ldi_sequence;
}
