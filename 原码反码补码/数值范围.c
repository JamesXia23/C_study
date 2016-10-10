#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	// int表示范围 INT_MIN-INT_MAX
	printf("%d,%d\n", INT_MAX, INT_MIN);	
	printf("%d,%d\n", INT_MAX + 1, INT_MIN);	
	printf("%d,%d\n", INT_MAX, INT_MIN - 1);

	// unsigned int表示范围 0-UINT_MAX
	printf("%u\n", UINT_MAX + 1);

	return 0;
}