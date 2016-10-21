#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	{
		int num1 = printf("%s\n", "hello world");//12
		int num2 = printf("hello world\n");	//12
		int num3 = printf("你好\n");	//以gbk编码存储，你好会解析出两个字符，因为一个字符占两个字节，所以共5个
		// utf-8是不定长的，根据左侧位1的个数来决定占用了几个字节
		// false的：
		// utf-8可以根据字的第一个字节移位推出长度的
		// 0xxxxxxx
		// 110xxxxx 10xxxxxx
		// 1110xxxx 10xxxxxx 10xxxxxx
		// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
		// 打印字符串时，返回打印的字节个数
		
		printf("%d,%d,%d\n", num1, num2, num3);
	}

	{
		// printf输出的时候已经把所有东西都变成字符，所有第一个num3打印的是“1,2\n”,故四个字节
		// 												第二个num3打印的是“55,66\n”,故六个字节
		int num1 = 1;
		int num2 = 2;
		int num3 = printf("%d,%d\n", num1, num2);//4

		printf("%d\n", num3);

		num1 = 55;
		num2 = 66;
		num3 = printf("%d,%d\n", num1, num2);//6

		printf("%d\n", num3);
	}
	/*
	总结:printf返回的是打印出来的字符串的字节数
	 */
	
	{
		int num1;
		int num2;
		int num3;
		char str[100] = {0};

		num3 = scanf("%d,%d", &num1, &num2); //2
		printf("%d\n", num3);
		num3 = scanf("%*d,%d", &num2);	//1
		printf("%d\n", num3);
		num3 = scanf("%s", str);
		printf("%d\n", num3);


		// scanf返回真正接收的参数个数,与接收什么类型无关
	}

	return 0;
}