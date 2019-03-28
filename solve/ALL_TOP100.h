/*
 *
 * Combine top100 of all subfiles and find the final top100
 * 
 * Author:  dreamstart 
 * 			2019.03.27
 *
 */

#ifndef ALL_TOP100
#define ALL_TOP100

#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
struct url_node {
	string url;
	int count;
};

bool cmp(url_node q, url_node w); //Redefining the judgment condition of the sort function

//Combine the top100 of all the subfiles and find all the top100 and output
void solve_top100(const string file_name, const int &nums);

#endif
