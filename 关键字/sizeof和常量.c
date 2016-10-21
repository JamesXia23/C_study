#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	// sizeof是编译时执行的，所以在sizeof得出来的结果可以看成常量
	int array[sizeof(int)];
	for (int i = 0; i < sizeof(int); ++i)
	{
		array[i] = i;
		printf("%d\n", array[i]);
	}
	return 0;
}
