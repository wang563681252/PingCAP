/*
 * 
 * Top100 calculates the number of URL occurrences in each subfile
 * 
 * Author: dreamstart 
 *         2019.03.26
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
string count_top100(int file_nums)
{
	string output_file = "subfile_top100.txt";
	ofstream wout;
	wout.open(output_file, ios::app);
	priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > que;
	unordered_map<string, int> ump;

	//Read each subfile and calculate the url of the top100 occurrences and write them to the same file
	for(int i = 1; i <= file_nums; i++)
	{
		string open_file = "hash_url_" + to_string(i) + ".txt";
		ifstream readin;
		readin.open(open_file);
		if(!readin.is_open()) 
		{
			continue;
		}

		//Find out the url of the top100
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
			++it;
		}

		//output
		pair<int, string> Put;
		for(int i = 1; i <= 100; i++)
		{
			if(que.empty() == 1) break;
			Put = que.top();
			que.pop();
			wout << Put.first << ' ' << Put.second << endl;
		}
		readin.close();
		if(!que.empty()) que.pop();//empty que
		ump.clear(); //empty ump
	}
	wout.close();
	return output_file;
}

// unit testing
/*
int main()
{
	count_top100(1);
	return 0;
}
*/
