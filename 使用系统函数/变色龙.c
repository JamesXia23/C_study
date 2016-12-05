#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#include <time.h>

void title(void *p);
void color(void *p);
void open(void *p);
int main(int argc, char const *argv[])
{
	//title计时间
	_beginthread(title, 0, NULL);
	//color换色
	_beginthread(color, 0, NULL);
	//open打开新窗口，慎用。。。
	// _beginthread(open, 0, NULL);
	system("pause");
	return 0;
}
void title(void *p)
{
	char cmd[100] = {0};
	int i = 0;

	while(1) {
	    sprintf(cmd, "title during %d seconds", ++i);
	    Sleep(1000);
	    system(cmd);
	}
}
void color(void *p)
{
	// time_t t;
	// unsigned int num = time(&t);
	// srand(num);
	srand((unsigned int)time(NULL));

	while(1) {
	    char cmd[100];
	    int num1 = rand() % 16;
	    int num2 = rand() % 16;
	    sprintf(cmd, "color %x%x", num1, num2);
	    system(cmd);

	}

}
void open(void *p)
{
	while(1) {
	    system("start");
	}
}