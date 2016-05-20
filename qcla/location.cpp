#include "location.h"

using namespace std;

void Location:: init(string x, string y, int z)
{
	setName(x);
	setCoefficients(y);
	setCoefficienti(z);
	
}

void Location::setLocation(string expression)
{
	int length = expression.length();
	
	int multi_index = expression.find("*",0);
	if(multi_index != -1)
	{
		coefficient_s = expression.substr(0, multi_index);
		name = expression.substr(multi_index+1, length-1-multi_index);
	}
	else
	{
		if(expression[0] == '-')
		{
			coefficient_s = "-1";
			name = expression.substr(1, length-1);
		}
		else
		{
			coefficient_s = "1";
			name = expression;
		}
	}
	cout << coefficient_s << " " << name << endl;
	//cout << multi_index << endl;
	
}
