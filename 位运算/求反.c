#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	// ȡ����������λ��һ��ȡ����������λһ��ȡ��
	{
		int a = 1;
		int b = ~1;

		printf("a = %d, b = %d\n", a, b);
		printf("a = %#x, b = %#x\n", a, b);
	}
	{
		unsigned int a = 1;
		unsigned int b = ~1;

		printf("a = %u, b = %u\n", a, b);
		printf("a = %#x, b = %#x\n", a, b);
	}
	return 0;
}