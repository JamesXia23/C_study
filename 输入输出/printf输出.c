#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	{
		unsigned short int unum = 65535;
		short int num = 124;

		printf("%hu,%hd\n", unum, num);
	}

	{
		unsigned long unum = 13590386468;
		long num = 13590386468;

		printf("%lu,%ld\n", unum, num);
	}
	//表示手机号码用long long 
	{
		unsigned long long unum = 13590386468;
		long long num = 13590386468;

		printf("%llu,%lld\n", unum, num);
	}
	return 0;
}