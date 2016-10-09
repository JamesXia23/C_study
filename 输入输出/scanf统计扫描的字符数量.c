#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char str[100];
	int num;
	// %n:可以统计扫描的字符数量  中文是一个字符两个字节
	scanf("%s%n", str, &num);
	printf("%s\n%d", str, num);
	return 0;
}