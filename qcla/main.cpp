#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "node.h"
#include "expression.h"
#include "eldi.h"
#include "formula.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
[4,5] -> s1+s2 <= 4 ; s3+s4 <= 1;
*/
extern void analyze_interval(string interval);

int main(int argc, char** argv) {

	string tempPath[] = {"s1","s2","s3","s1","s4"};
	string formula = " [ 4 ,  5 ] | ( -s1  - 2 * s2) <= 4 ; ((-2)*s1 + s4) <= 1";
	int length = sizeof(tempPath)/sizeof(string);
	
	ELDI phi;
	phi.setEldi(formula);
	show(phi);

	string lower_bound = phi.getlowerB();
	string upper_bound = phi.getupperB();
	vector<Node> path;
	vector<Node>::iterator pathIT;
	for(int i = 0; i < length; i++)
	{
		Node tempnode;
		char temptime = 'a'+ i;
		stringstream stream;
		stream << temptime;
		tempnode.setName(tempPath[i]);
		tempnode.setTime(stream.str());
		path.push_back(tempnode);
	}

	string alguments_all;
	string alguments_ex;
	string all_expression;
	string ex_expression;
	string bounds_inequaltions_expression;
	
	alguments_all = get_alguments_all(path);
	alguments_ex = get_alguments_ex();
	

	ex_expression = ex(alguments_ex);
	bounds_inequaltions_expression = get_bounds_inequaltions(lower_bound, upper_bound, path);
	all_expression = all(alguments_all + bounds_inequaltions_expression + " impl " + ex_expression);


	

	return 0;
}
