/*
 * 
 * Top100 calculates the number of URL occurrences in each subfile
 * 
 * Author: dreamstart 
 *         2019.03.26
 */

#ifndef COUNT_SUBFILE
#define COUNT_SUBFILE

#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
using namespace std;


//Read each subfile and calculate the url of the top100 occurrences and write them to the same file
string count_top100(int file_nums);

#endif
