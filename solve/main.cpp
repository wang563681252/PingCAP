/*
 * 1.Hash each url into the subfile
 * 2.Count the top100 url in each subfile and output on a file
 * 3.Find the total top100 and output it
 * 
 * Author: dreamstart
 *		   2019.03.27
 */


#include <cstdio>
#include <cstring>
#include <cmath>
#include "count_subfile_top100.h"
#include "split_url_file.h"
#include "ALL_TOP100.h"
using namespace std;
int file_nums = 200; //The url subfile numbers

int main()
{
	string file_name = "data.txt"; //the url txt name
	file_nums = split_file(file_name, file_nums); //the nums is number of the subfile
	
	//Find the top100 of the number of url occurrences in each subfile and write it to a file
	string final_file = count_top100(file_nums); 

	//Find the total top100 and output it
	solve_top100(final_file, file_nums);
	return 0;
}
