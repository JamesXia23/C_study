#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	{
		int num = 01234;
		printf("%o\n", num);
		printf("%#o\n", num);
	}
	{
		int num = 0x123ad;
		printf("%x\n", num);
		printf("%#x\n", num);
	}
	{
		// 以16进制打印出浮点数
		float abc = 123.45;
		double cde = 18523.555;
		printf("%a\n", abc);	//0x1.edccccp+6 p表示16，作为底数，与e类似
		printf("%la\n", cde);	//0x1.216e38p+14 
	}
	

	return 0;
}