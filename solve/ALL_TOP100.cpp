/*
 *
 * Combine top100 of all subfiles and find the final top100
 *
 * Author:  dreamstart 
 * 			2019.03.27
 */

#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "ALL_TOP100.h"
using namespace std;

bool cmp(url_node q, url_node w) //Redefining the judgment condition of the sort function
{
	return q.x > w.x;
}

//Combine the top100 of all the subfiles and find all the top100 and output
void solve_top100(const string file_name, const int &nums) 
{
	ifstream readin;
	readin.open(file_name);
	ofstream wout;
	wout.open("url_top100.txt", ios::app);

	//Put all the subfiles top100 in arr
	url_node arr[nums * 100 + 5];
	int val;
	string s;
	int tot = 0;
	while(readin >> val >> s)
	{
		arr[tot].url = s;
		arr[tot].count = val;
		tot++;
	}

	//Sort arr from x to large with x as the key
	sort(arr, arr + tot, cmp);
	for(int i = 0; i < 100; i++)
	{
		if(arr[i].x == 0) break;
		wout << arr[i].url << " The number of occurrences:" << arr[i].count << endl;
	}
	readin.close();
	wout.close();
	return ;
}
