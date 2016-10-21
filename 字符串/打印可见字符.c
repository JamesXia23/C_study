#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	// 从33到126是可见字符
	for (int i = 33; i < 127; ++i)
	{
		printf("%c\n", i);
	}
	return 0;
}