/*
 *
 * unit test to count_subfile_top100.cpp
 *
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
using namespace std;
const int file_nums = 200; //The number of the subfile

typedef unordered_map<string, int>::iterator MyIte;
int main()
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
		string s;
		while(readin >> s)
		{
			ump[s]++;
		}

		//Maintain a small root heap of size 100
		MyIte it = ump.begin();
		pair<int, string> PUT, temp;
		while(it != ump.end())
		{
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

		pair<int, string> Put;
		for(int i = 1; i <= 100; i++)
		{
			if(que.empty() == 1) break;
			Put = que.top();
			que.pop();
			wout << Put.first << ' ' << Put.second << endl;
		}
		readin.close();
		while(!que.empty()) que.pop();
		ump.clear();
	}
	wout.close();
	return 0;
}
