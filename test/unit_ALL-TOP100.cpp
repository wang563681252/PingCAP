/*
 *
 * unit test to ALL-TOP100.cpp
 *
 */

#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int nums = 200; //Number of subfiles
struct url_node {
	string s;
	int x;
};

bool cmp(url_node q, url_node w) //Redefining the judgment condition of the sort function
{
	return q.x > w.x;
}

//Combine the top100 of all the subfiles and find all the top100 and output
int main()
{
	string file_name = "subfile_top100.txt"; 
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
		arr[tot].s = s;
		arr[tot].x = val;
		tot++;
	}

	//Sort arr from x to large with x as the key
	sort(arr, arr + tot, cmp);
	for(int i = 0; i < 100; i++)
	{
		if(arr[i].x == 0) break;
		wout << arr[i].s << endl << "The number of occurrences:" << arr[i].x << endl;
	}
	readin.close();
	wout.close();
	return 0;
}
