#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	{
		// 与0异或值不变，与1异或值改变
		unsigned char a = 255;
		printf("%d\n", a^0);
		printf("%d\n", a);
	}
	{
		// 不引入变量的交换
		int a = 10;
		int b = 20;

		printf("a = %d, b = %d\n", a, b);
		a = a^b;
		b = a^b;
		a = a^b;
		printf("a = %d, b = %d\n", a, b);
	}
	
	
	return 0;
}