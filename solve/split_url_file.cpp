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
const int MAX_file = 3e6;

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

int split_file(const string file_name, const int &file_nums) //Write large files to small files by hash value
{
	map<int, int> flag; //Output file with hash value
	map<int, int> file_size; //Record how many urls the file stores
	//Initialize the hash value location
	for(int i = 1; i <= file_nums; i++) 
	{
		flag[i] = i;
	}

	ifstream turn_on;
	turn_on.open(file_name);
	if(!turn_on.is_open()) 
	{
		cout << "The file was not found" << endl;
		exit(-1);
	}

	//Write the file by value after the s string hash
	int tot_hash_file = file_nums; //Record the number of file expansions
	string s;
	while(turn_on >> s) 
	{
		//Calculate the hash value and calculate which folder to put in
		int hash_s = Hash(s);
		hash_s = hash_s % file_nums + 1;
		if(file_size[flag[hash_s]] >= MAX_file) {
			flag[hash_s] = tot_hash_file + 1;
			tot_hash_file++;
		}
		file_size[flag[hash_s]]++; 


		//output
		ofstream write_in;
		write_in.open("hash_url_" + to_string(hash_s) + ".txt", ios::app);
		write_in << s << endl;
        write_in.close();
	}
	turn_on.close();
	return tot_hash_file;
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
