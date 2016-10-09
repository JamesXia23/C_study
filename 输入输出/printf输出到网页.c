#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	// 声明为html
	printf("Content-type:text/html\n\n");//注意要两个换行，而且要把.exe改成.cgi然后放入服务器的.cgi-bin文件夹下
	printf("你好，天朝\n");
	return 0;
}