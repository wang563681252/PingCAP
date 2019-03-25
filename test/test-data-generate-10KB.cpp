/*
	Randomly generate a 10KB url file

	Author:dreamstart(Zhaopeng Wang)
*/

#include <cstdio>
#include <cstdlib>
using namespace std;
const long long Size = 1e4;  //10KB file has about 1e4 byte
const long long per_url_size = 100;  //Byte length per url

bool check_url_bit(int x)  //Guaranteed output is in English and numbers
{
	if(x >= 48 && x <= 57 || x >= 65 && x <= 90 || x >= 97 && x <= 122) return 1;
	return 0;
}

int main()
{
	int before_url, after_url, out_put;  
	freopen("test-10KB.txt", "w", stdout);
	long long tot = Size / per_url_size;  //The number of url

	for(long long i = 1; i <= tot; i++)
	{
		before_url = rand() % per_url_size + 1;
		after_url = 100 - before_url;
		out_put = 0;

		for(int j = 1; j <= before_url; j++) 
		{
			out_put = rand() % 126 + 1;
			while(check_url_bit(out_put) == 0) out_put = rand() % 126 + 1;
			printf("%c", out_put);
		}
		printf(".com/");
		for(int j = 1; j <= after_url; j++) {
			out_put = rand() % 126 + 1;
			while(check_url_bit(out_put) == 0) out_put = rand() % 126 + 1;
			printf("%c", out_put);
		}
		printf("\n");
	}

	return 0;
}
