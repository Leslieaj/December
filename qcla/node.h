#ifndef _NODE_H_
#define _NODE_H_

#include <string>

using namespace std;

class node 
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

#endif
