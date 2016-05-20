#include <iostream>
#include "formula.h"
#include "eldi.h"

using namespace std;

/*
	remove something like space , parentheses and so on
*/
string remove_char(string s, char c)
{
	string temp;
	temp = "";
	int length = s.length();
	for(int i = 0; i < length; i++)
	{
		if(s[i] != c)
		temp = temp +  s[i];
	}
	
	return temp;
}

/*
	analyze the original ELDI to get the bounds and every LDI
*/
void analyze_formula(string formula, string &interval, string &eldi_formula)
{
	int formula_len = formula.length();
	cout << formula_len << endl;
	
	string temp = "";
	//string interval;
	//string eldi_formula;
	for(int i = 0; i < formula_len; i++)
	{
		if(formula[i] != '|')
		{
			temp = temp + formula[i];
			continue;
		}
		if(formula[i] == '|')
		{
			interval = temp;
			temp = "";
			continue;
		}
	}
	eldi_formula = temp;
	
	//cout << interval << endl;
	//cout << eldi_formula << endl;
}

/*
	analyze the ELDI expression to get every LDI
*/
void analyze_eldi(string expression, vector<string>& sequence)
{
	//vector<string> ldi_sequence;
	string temp = "";
	int length = expression.length();
	for(int i = 0; i < length; i++)
	{
		if(expression[i] != ';')
		{
			temp = temp + expression[i];
			continue;
		}
		else
		{
			sequence.push_back(temp);
			temp = "";
			continue;
		}
	}
	sequence.push_back(temp);
	
	vector<string>::iterator it;
	for(it = sequence.begin(); it != sequence.end(); it++)
	{
		cout << *it << endl;	
	}
	//return ldi_sequence;
}

/*
	analyze the bound interval to get the lower bound and the upper bound
*/
void analyze_interval(string interval, string &lowerB, string &upperB)
{
	int length = interval.length();
	string lowerB_in_it = "";
	string upperB_in_it = "";

	
	int comma_index = interval.find(",",0);
	lowerB_in_it = interval.substr(0, comma_index);
	upperB_in_it = interval.substr(comma_index+1, length-1-comma_index);

	//string lowerB;
	lowerB = getbound(lowerB_in_it);
	
	//string upperB;
	upperB = getbound(upperB_in_it);

	cout << length << endl;
	cout << comma_index << endl;
	cout << lowerB_in_it << endl;
	cout << upperB_in_it << endl;
	cout << lowerB << endl;
	cout << upperB << endl;
}

string getbound(string s)
{
	string temp = "";
	int s_len = s.length();
	
	for(int i = 0; i < s_len; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			temp = temp + s[i];
		}
	}
	
	return temp;
}

/*
	analyze LDI to get each location and coefficient and value
*/
void analyze_ldi(string expression, string &value)
{
	vector<Location> location_sequence;
	int length = expression.length();
	string mvalue_in_it = "";
	int lessthan_index;
	lessthan_index = expression.find("<", 0);
	mvalue_in_it = expression.substr(lessthan_index+1, length-1-lessthan_index);
	value = getMvalue(mvalue_in_it);
	
	vector<string> location_and_coefficient;
	string lc_in_it = "";
	lc_in_it = expression.substr(0, lessthan_index);
	lc_in_it = remove_char(lc_in_it, ' ');
	lc_in_it = remove_char(lc_in_it, '(');
	lc_in_it = remove_char(lc_in_it, ')');
	cout << lc_in_it << endl;
	int lc_length = lc_in_it.length();
	string lc_temp = "";
	if(lc_in_it[0] == '-' || lc_in_it[0] == '+')
	{
		lc_temp = lc_temp + lc_in_it[0];
	}
	for(int i = 0; i < lc_length; i++)
	{
		if(lc_in_it[i] != '+')
		{
			lc_temp = lc_temp + lc_in_it[i];
			continue;
		}
		else
		{
			location_and_coefficient.push_back(lc_temp);
			lc_temp = "";
			continue;
		}
	}
	location_and_coefficient.push_back(lc_temp);
	
	vector<string>::iterator lc_it;
	for(lc_it = location_and_coefficient.begin(); lc_it != location_and_coefficient.end(); lc_it++)
	{
		Location location;
		string temp = *lc_it;
		cout << *lc_it << endl;
		location.setLocation(temp);
		location_sequence.push_back(location);
	}
	
}

string getMvalue(string s)
{
	string temp = "";
	int s_len = s.length();
	
	for(int i = 0; i < s_len; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			temp = temp + s[i];
		}
	}
	
	return temp;
}
