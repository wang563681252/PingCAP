/*
 *
 * unit test to split_url_file.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;
const int file_nums = 200; //The url subfile numbers

int Hash(const string &s)  //hash function
{
	const int base = 107;
	int res = 0;
	for(int i = 0; i < s.size(); i++)
	{
		res = (res * base + s[i]) % 10000;
	}
	return res;
}

int main()
{
	string file_name = "test4.txt";
	ifstream turn_on;
	turn_on.open(file_name);
	if(!turn_on.is_open()) 
	{
		cout << "The file was not found" << endl;
		exit(-1);
	}
	string s;
	while(turn_on >> s) 
	{
		int hash_s = Hash(s);
		hash_s = hash_s % file_nums + 1;
		ofstream write_in;
		write_in.open("hash_url_" + to_string(hash_s) + ".txt", ios::app);
		write_in << s << endl;
        write_in.close();
	}
	turn_on.close();
	return 0;
}
