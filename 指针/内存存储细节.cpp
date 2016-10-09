#include <iostream>
using namespace std;

int a = 3;	//已初始化的全局变量	
int b;		//未初始化的全局变量	
int main(int argc, char const *argv[])
{
	int c;	//局部变量	
	char* str1 = "hello";//指针指向字符串		
	char str2[] = "hello";//数组保存字符串	

	printf("%p\n", &a);			//0000000000409010	DATA区
	printf("%p\n", &b);			//000000000040e040	BSS区
	printf("%p\n", &c);			//000000000024fe4c	栈区
	printf("%p\n", str1);		//000000000040a031	"hello"字符串的地址，RO.DATA区
	printf("%p\n", &str1);		//000000000024fe40	指针变量str1的地址，栈区
	printf("%p\n", str2);		//000000000024fe30	相当于str2[0]的地址	str2++为str[1]的地址，只加了一个字节
	printf("%p\n", &str2);		//000000000024fe30	整个数组的地址		&str2++为整个数组加一，单位为整个数组，在这里看来就是6个字节

	return 0;
}

