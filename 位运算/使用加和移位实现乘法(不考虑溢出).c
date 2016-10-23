#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int x,y;
	long res = 0;
	int time = 32;

	scanf("%d %d", &x, &y);
	printf("%#x %#x\n", x, y);
	for (int i = 0; i < time; ++i)
	{
		int temp = x & 1;
		temp ? (res += y << i) : 1;
		x = x >> 1;
		printf("%#x\n", res);
	}
	printf("%d\n", res);
	
	return 0;
}