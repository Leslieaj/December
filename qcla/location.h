#ifndef _LOCATION_H_
#define _LOCATION_H_

#include <string>
#include <iostream>
using namespace std;

class Location
{
	public:
		void setName(string x)
		{
			name = x;
		}
		string getName()
		{
			return name;
		}
		void setCoefficients(string y)
		{
			coefficient_s = y;
		}
		string getCoefficients()
		{
			return coefficient_s;
		} 
		void setCoefficienti(int z)
		{
			coefficient_i = z;
		}
		int getCoefficienti()
		{
			return coefficient_i;
		}
		
		void init(string x, string y, int z);
		void setLocation(string expression);
	private:
		string name;
		string coefficient_s;
		int coefficient_i;
};

#endif
