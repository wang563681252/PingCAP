/*
 *
 * Split large files into small files
 *
 * Author:  dreamstart 
 * 			2019.03.26
 */


#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iostream>
#include <map>
#include "split_url_file.h"
using namespace std;

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

void split_file(const string file_name, const int &file_nums) //Write large files to small files by hash value
{
	map<int, int> flag; //Mark how many urls are stored in this subfile

	ifstream turn_on;
	turn_on.open(file_name);
	if(!turn_on.is_open()) 
	{
		cout << "The file was not found" << endl;
		exit(-1);
	}

	//Write the file by value after the s string hash
	string s;
	while(turn_on >> s) 
	{
		int hash_s = Hash(s);
		hash_s = hash_s % file_nums + 1;

		//output
		ofstream write_in;
		write_in.open("hash_url_" + to_string(hash_s) + ".txt", ios::app);
		write_in << s << endl;
        write_in.close();
	}
	turn_on.close();
	return ;
}

//unit testing
/*
int main()
{
	string file_name = "data.txt";
	split_file(file_name);
	return 0;
}
*/
