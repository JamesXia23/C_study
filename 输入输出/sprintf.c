#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char str1[100];
	scanf("%s", str1);
	char str2[100];
	// color 改变命令行颜色
	sprintf(str2, "color %s", str1);	
	system(str2);
	return 0;
}