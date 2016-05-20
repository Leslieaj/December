#ifndef _LDI_H_
#define _LDI_H_
#include <vector>
#include "location.h"

class LDI
{
	public:
		void setLdiExpression(string expression)
		{
			ldi_expression = expression;
		}
		string getLdiExpression()
		{
			return ldi_expression;
		}
		void setValue(string v)
		{
			value = v;
		}
		string getValue()
		{
			return value;
		}
		void setLdi(string expression);
		vector<Location> getLdi();
	private:
		string ldi_expression;
		string value;
		vector<Location> ldi; 
};
#endif
