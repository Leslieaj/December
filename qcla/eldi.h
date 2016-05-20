#ifndef _ELDI_H_
#define _ELDI_H_

#include <string>
#include "ldi.h"
//using namespace std;

class ELDI
{
	public:
		void setEldiExpression(string expression)
		{
			eldi_expression = expression;
		}
		string getEldiExpression()
		{
			return eldi_expression;
		}
		void setInterval(string i)
		{
			interval = i;
		}
		string getInterval()
		{
			return interval;
		}
		void setLB(string lb);
		int getLB()
		{
			return lower_bound;
		}
		string getlowerB()
		{
			return lowerB;
		}
		void setUB(string ub);
		int getUB()
		{
			return upper_bound;
		}
		string getupperB()
		{
			return upperB;
		}
		
		void setEldi(string formula);
		vector<string> get_ldi_sequence();
		vector<LDI> getEldi()
		{
			return eldi;
		}
		//void analyze_eldi(string expression);
	private:
		string interval;
		int lower_bound;
		string lowerB;
		int upper_bound; 
		string upperB;
		string eldi_expression;
		vector<string> ldi_sequence;
		vector<LDI> eldi;
};
#endif
