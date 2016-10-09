#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char* str = "hello";
	putchar(*str++);	//输出为h，因为str是指针变量，可以进行++运算(变量能做左值)
	char str2[] = "world";
	putchar(*str2++);	//编译错误，因为str2是数组首地址，所以是地址常量，不能进行++运算(常量不能做左值)cannot increment value of type 'char [6]'
	
	return 0;
}
