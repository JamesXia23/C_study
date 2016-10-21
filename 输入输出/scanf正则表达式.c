#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char str[100] = {0};
	/*
	//scanf 默认是以空格，回车作为分隔符的，如果想修改，可以使用正则
	scanf("%[^=]", str);// ^代表非，即代表扫描到非=就继续扫描，也就意味着=结束
	printf("%s\n", str);

	scanf("%[^,]", str);// ,作为结束符
	printf("%s\n", str);
	*/

	/*
	// 接收数字
	scanf("%[0-9]", str);
	printf("%s\n", str);
	*/
	// 邮箱(失败了)
	// scanf("%[0-9A-Za-z]@%[_0-9A-Za-z].com", str);
	// printf("%s\n", str);
	return 0;
}