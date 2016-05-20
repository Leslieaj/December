#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "node.h"
//using namespace std;

/*
	Deal with the "all" and get the final expression.
*/
string all(string s);

/*
	Deal with the "ex"
*/
string ex(string s);

/*
	Get the alguments for "all"
*/
string get_alguments_all(vector<Node> path);

/*
	Get alguments for "ex"
	------------------------------------- wait to code
*/
string get_alguments_ex();

/*
	Get bounds inequaltions 
*/
string get_bounds_inequaltions(string lower_bound, string upper_bound, vector<Node> path);

/*
    consider chop at one point to generate the inequaltions
*/
string onechop_inequaltions(int chop_point_location);

/*
	From ELDI to alguments inequaltions
*/
string generateELDI_inequaltions();

#endif
