/*
 *
 * Split large files into small files
 *
 * Author:  dreamstart 
 * 			2019.03.26
 */

#ifndef SPLIT_URL
#define SPLIT_URL

#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

int Hash(const string &s); //hash function
void split_file(const string file_name, const int &file_nums); //Write large files to small files by value

#endif
