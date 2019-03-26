/*
 * 
 * Top100 calculates the number of URL occurrences in each subfile
 * Ended  Time*  : 二  3/26 16:54:01 2019
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include "count_subfile_top100.h"
using namespace std;

typedef unordered_map<string, int>::iterator MyIte;
void count_top100(const int file_nums)
{
	string output_file = "subfile_top100.txt";
	ofstream wout;
	wout.open(output_file, ios::app);
	for(int i = 1; i <= file_nums; i++)
	{
		priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > que;
		string open_file = "hash_url_" + to_string(i) + ".txt";
		ifstream readin;
		readin.open(open_file);
		if(!readin.is_open()) 
		{
			continue;
		}
		unordered_map<string, int> ump;
		string s;
		while(readin >> s)
		{
			ump[s]++;
		}
		MyIte it = ump.begin();
		while(it != ump.end())
		{
			pair<int, string> PUT, temp;
			PUT.first = it->second;
			PUT.second = it->first;
			if(que.size() < 100) que.push(PUT);
			else {
				temp = que.top();
				if(temp.first < PUT.first) {
					que.pop();
					que.push(PUT);
				}
			}
		}
		pair<int, string> Put;
		for(int i = 1; i <= 100; i++)
		{
			Put = que.top();
			que.pop();
			wout << Put.first << ' ' << Put.second << endl;
		}
	}
	wout.close();
}

// unit testing
/*
int main()
{
	count_top100(1);
	return 0;
}
*/
