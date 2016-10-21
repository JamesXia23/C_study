#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	enum {
		星期一 = 1,
		星期二, 星期三, 星期四, 星期五, 星期六, 星期日
	};

	int day;
	while(scanf("%d", &day) != EOF)
	{
		switch (day)
		{
			case 星期一:
				printf("Mon\n");
				break;
			case 星期二:
				printf("Tus\n");
				break;
			case 星期三:
				printf("Web\n");
				break;
			case 星期四:
				printf("Thr\n");
				break;
			case 星期五:
				printf("Fri\n");
				break;
			case 星期六:
				printf("Sat\n");
				break;
			case 星期日:
				printf("Sun\n");
				break;
			default:
				printf("error\n");
		}
	}
	return 0;
}

