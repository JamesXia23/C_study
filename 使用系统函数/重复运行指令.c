#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int times = 0;
	char cmd[100] = {0};
	char strcmd[200];

	scanf("%[^\n]", cmd);
	scanf("%d", &times);
	
	/**
	 * for /l %i :循环
	 * in (1,1,n) :以1为起点，每次加1，直到n
	 * do .... :要执行的指令
	 */
	sprintf(strcmd, "for /l %%i in (1,1,%d) do %s", times, cmd);

	system(strcmd);
	return 0;
}