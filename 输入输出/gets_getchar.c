#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char str[100];
	gets(str);

	system(str);
	return 0;
}