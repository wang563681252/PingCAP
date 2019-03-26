#include <fstream>
#include <cstring>
#include <iostream>
#include "split_url_flie.h"
using namespace std;
const int flie_nums = 200; //The url flie numbers

int Hash(const string &s)
{
	const int base = 107;
	int res = 0;
	for(int i = 0; i < s.size(); i++)
	{
		res = (res * base + s[i]) % 10000;
	}
	return res;
}

void flie(const string &flie_name)
{
	ifstream turn_on;
	turn_on.open(flie_name);
	string s;
	while(turn_on >> s) 
	{
		int hash_s = Hash(s);
		hash_s = hash_s % flie_nums;
		ofstream write_in;
		write_in.open("hash_url_" + to_string(hash_s) + ".txt", ios::app);
		write_in << s << endl;
        write_in.close();
	}
	return ;
}

//unit testing
/*
int main()
{
	string flie_name = "data.txt";
	flie(flie_name);
	return 0;
}
*/
