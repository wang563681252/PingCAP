/*
 *
 * Split large files into small files
 *
 */


#include <fstream>
#include <cstring>
#include <iostream>
#include "split_url_flie.h"
using namespace std;
const int file_nums = 200; //The url subfile numbers

int Hash(const string &s)  //hash函数
{
	const int base = 107;
	int res = 0;
	for(int i = 0; i < s.size(); i++)
	{
		res = (res * base + s[i]) % 10000;
	}
	return res;
}

void split_file(const string &file_name) //将大文件按值写入小文件
{
	ifstream turn_on;
	turn_on.open(file_name);
	string s;
	while(turn_on >> s) 
	{
		int hash_s = Hash(s);
		hash_s = hash_s % file_nums;
		ofstream write_in;
		write_in.open("hash_url_" + to_string(hash_s) + ".txt", ios::app);
		write_in << s << endl;
        write_in.close();
	}
	return ;
}

//unit testing
int main()
{
	string file_name = "data.txt";
	split_file(file_name);
	return 0;
}
