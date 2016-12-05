#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>

void run(void *p);
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 5; ++i)
	{
		// 第一个参数为线程入口函数相当于线程的main
		_beginthread(run, 0, NULL);
	}
	
	//加pause的原因是：如果不加，那么当主线程挂了，子线程也会挂
	system("pause");
	return 0;
}
// 入口函数参数一定要是void *
void run(void *p)
{
	MessageBox(0, TEXT("hello"), TEXT("hacker"), 0);
}