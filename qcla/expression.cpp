#include "expression.h"

using namespace std;

/*
	Deal with the "all" and get the final expression.
*/
string all(string s)
{
	stringstream st;
	string final;
	st << "all" << "(" << s << ")";
	final = st.str();
	cout << final << endl;
	return final;
}

/*
	Deal with the "ex"
*/
string ex(string s)
{
	stringstream st;
	string tempEX;
	st << "ex" << "(" << s << ")";
	tempEX = st.str();
	cout << tempEX << endl;
	return tempEX;
}

/*
	Get the alguments for "all"
*/
string get_alguments_all(vector<Node> path)
{
	string alguments_all = "{";
	vector<Node>::iterator it;
	
	for(it = path.begin(); it != path.end(); it++)
	{
		if( it != path.end() -1 )
		{
			alguments_all = alguments_all + it->getTime() + ",";
		}
		else
		{
			alguments_all = alguments_all + it->getTime();
		}
		
	}
	alguments_all = alguments_all + "},";
	
	cout << alguments_all << endl;
	
	return alguments_all;
}

/*
	Get alguments for "ex"
	------------------------------------- wait to code
*/
string get_alguments_ex()
{
	string alguments_ex;
	alguments_ex = "{m, n}, ";
	return alguments_ex;
}

/*
	Get bounds inequaltions 
*/
string get_bounds_inequaltions(string lower_bound, string upper_bound, vector<Node> path)
{
	string bounds_inequaltions;
	stringstream st;
	bounds_inequaltions = "(" + lower_bound + "<=";
	vector<Node>::iterator it;
	for(it = path.begin(); it != path.end(); it++)
	{
		if( it != path.end() -1 )
		{
			bounds_inequaltions = bounds_inequaltions + it->getTime() + "+";
		}
		else
		{
			bounds_inequaltions = bounds_inequaltions + it->getTime();
		}
	}
	bounds_inequaltions = bounds_inequaltions + "<=" + upper_bound + ")";
	cout << bounds_inequaltions << endl;
	return bounds_inequaltions;
}

