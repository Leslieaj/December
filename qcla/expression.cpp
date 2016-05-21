#include "expression.h"
#include <stdlib.h>
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
/*
	build antecedent
*/
string build_antecedent(int node_index)
{
	string antecedent;
	stringstream sstream;
	sstream << node_index;
	string s = sstream.str();
	antecedent	= "n = " + s;
	return antecedent;
}

/*
    consider chop at one point to generate the inequaltions
*/
string onechop_inequaltions(vector<string> mvalue, vector<Node> &path, vector< vector<Lcnode> > &matrix)
{
	vector<Node>::iterator nodeIT;
	vector<string>::iterator mvalueIT = mvalue.begin();
	int node_index;
	string temp;
	for(nodeIT = path.begin(),node_index = 1; nodeIT != path.end(); nodeIT++, node_index++)
	{
		temp = temp + "(";
		
		string antecedent = build_antecedent(node_index);
		temp = temp + antecedent + " impl ";
		
		string chop_lefttime_valid = chop_lefttime("m", *nodeIT);
		temp = temp + chop_lefttime_valid;

		int flag = 0;
		vector<Node> chopleft_path;
		chopleft_path.assign(path.begin(), nodeIT+1);
		mvalueIT = mvalue.begin();
		string left_mvalue = *mvalueIT;
		flag = 0;
		string leftldi = ldi_inequaltions(left_mvalue, flag, chopleft_path, matrix);
		if(leftldi != "")
		{
			temp = temp + " and " + leftldi;
		}
		vector<Node> chopright_path;
		chopright_path.assign(nodeIT, path.end());
		string right_mvalue = *(mvalueIT+1);
		flag = 1;
		string rightldi = ldi_inequaltions(right_mvalue, flag, chopright_path, matrix);
		if(rightldi != "")
		{
			temp = temp + " and " + rightldi;
		}

		temp = temp + ")";
		if(node_index != path.size())
		{
			temp = temp + " and ";
		}
	}
	return temp;
}

string ldi_inequaltions(string value, int flag, vector<Node> &node_path, vector< vector<Lcnode> > &matrix)
{
	string temp = "";
	vector< vector<Lcnode> >::iterator matrix_it = matrix.begin()+flag;
	vector<Node>::iterator node_it;
	for(node_it = node_path.begin(); node_it != node_path.end(); node_it++)
	{
		Node node = *node_it;
		string node_name = node.getName();
		vector<Lcnode> lcnode_sequence = *matrix_it;
		vector<Lcnode>::iterator lcnode_sequence_it;
		for(lcnode_sequence_it = lcnode_sequence.begin(); lcnode_sequence_it != lcnode_sequence.end(); lcnode_sequence_it++)
		{
			Lcnode lcnode = *lcnode_sequence_it;
			string lcnode_name = lcnode.getName();
			if(node_name == lcnode_name)
			{
				string coefficient_s = lcnode.getCoefficient();
				int coefficient_i = atoi(coefficient_s.c_str());
				string staytime;
				if(flag == 0)
				{
					if(node_it == node_path.end()-1)
					{
						staytime = "m";
					}
					else
					{
						staytime = node.getTime();
					}
				}
				if(flag == 1)
				{
					if(node_it == node_path.begin() )
					{
						staytime = "(" + node.getTime() + "-" + "m" + ")"; 
					}
					else
					{
						staytime = node.getTime();
					}
				}
				
				if(coefficient_i < 0)
				{
					if(coefficient_i == -1)
					{
						temp = temp + "-" + staytime;
					}
					else
					{
						temp = temp + coefficient_s + "*" + staytime;	
					}
				}
				if(coefficient_i > 0)
				{
					if(coefficient_i == 1)
					{
						temp = temp + staytime;
					}
					else
					{
						temp = temp + "+" + coefficient_s + "*" + staytime;
					}						
				}
			}
		}
	}

	if(temp != "")
	{
		temp = temp + "<=" + value ;
	}

	return temp;
}
string chop_lefttime(string m, Node node)
{
	string temp = "";
	string time = node.getTime();
	temp = "0 <= " + m + " <= " + time;
	return temp;
}

