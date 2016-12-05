#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	//打开记事本5次
	int i = 0;
GOTO:if (i++ < 5)
{
	system("start notepad");//用start异步执行
	goto GOTO;
}

	return 0;
}