#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char str[100];
	int num;
	// %n:可以统计扫描的字符数量  中文是一个字符两个字节
	scanf("num=%d,str=%s", &num, str);//创建具有这样格式的txt文件即可
	printf("%s\n%d\n", str, num);
	return 0;
}