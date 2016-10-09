#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	// 输出到网页
	puts("Content-Type:text/html;\n\n");

	// puts在控制台自动换行
	puts("aaa<br>");
	putchar('A');
	putchar(65);
	putchar('A'+32);
	return 0;
}