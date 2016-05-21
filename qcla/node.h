#ifndef _NODE_H_
#define _NODE_H_

#include <string>

using namespace std;

class Node 
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
		void setTime(string y)
		{
			time = y;
		}
		string getTime()
		{
			return time;
		}

	private:
		string name;
		string time;
};

class Lcnode
{
	public:
		void setName(string n)
		{
			name = n;
		}
		string getName()
		{
			return name;
		}
		void setCoefficient(string c)
		{
			coefficient = c;
		}
		string getCoefficient()
		{
			return coefficient;
		}
	private:
		string name;
		string coefficient;
};

#endif
