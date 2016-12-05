#include <stdio.h>
#include <stdlib.h>

int reverseFor(int num);
int reverseWhile(int num);
int reverseDoWhile(int num);
int reverseGoTo(int num);
char* reverseDigui(int num);// 重点
int main(int argc, char const *argv[])
{
	int num;
	scanf("%d", &num);

	// int newNum = reverseFor(num);
	// int newNum = reverseWhile(num);
	// int newNum = reverseDoWhile(num);
	// int newNum = reverseGoTo(num);
	char *newNum = reverseDigui(num);
	printf("%s\n", newNum);
	// printf("%d\n", newNum);
	
	return 0;
}

int reverseFor(int num)
{
	int newNum;
	for (newNum = 0; num; num = num/10)
	{
		int i = num % 10;
		newNum = newNum * 10 + i;
	}
	return newNum;
}
int reverseWhile(int num)
{
	int newNum = 0;
	while(num)
	{
		int i = num % 10;
		newNum = newNum * 10 + i;
		num /= 10;
	}
	return newNum;
}
int reverseDoWhile(int num)
{
	int newNum = 0;
	do
	{
		int i = num % 10;
		newNum = newNum * 10 + i;
		num /= 10;
	}while(num);
	return newNum;
}
int reverseGoTo(int num)
{
	int newNum = 0;
rev:if (num)
{
	int i = num % 10;
	newNum = newNum * 10 + i;
	num /= 10;
	goto rev;
}
	return newNum;
}
char* reverseDigui(int num)
{
	// 不能用字符数组，因为字符数组为在栈上，函数返回时已经被清除了
	char *newNum = (char *)malloc(100);
	if (!num)
	{
		return "";
	}
	
	int i = num % 10;
	char *str = reverseDigui(num/10);
	sprintf(newNum, "%d%s", i, str);
	
	return newNum;
}