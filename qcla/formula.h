#ifndef _FORMULA_H_
#define _FORMULA_H_

#include <string>
#include <vector>
using namespace std;

/*
	remove something like space , parentheses and so on
*/
string remove_char(string s, char c);

/*
	analyze the original ELDI to get the bounds and ELDI expression
*/
void analyze_formula(string formula, string &interval, string &eldi_formula);

/*
	analyze the ELDI expression to get every LDI
*/
void analyze_eldi(string expression, vector<string>& sequence);

/*
	analyze the bound interval to get the lower bound and the upper bound
*/
void analyze_interval(string interval, string &lowerB, string &upperB);
string getbound(string s);

/*
	analyze LDI to get each location and coefficient
*/
void analyze_ldi(string expression, string &value);
string getMvalue(string s);
#endif



