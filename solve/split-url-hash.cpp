#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

void split_flies(const char *url_flie_name)
{
	if(freopen(url_flie_name, "r", stdin) == NULL) 
	{
		printf("The file was not found\n");
		exit(-1);
	}
	string s;
	while(cin >> s)
	{
		if(s.substr(0, 4).find("http") != string::npos) s.erase(0,5);
		while(s[0] == '/' || s[0] == ':') s.erase(s.begin());

	}
	return ;
}
