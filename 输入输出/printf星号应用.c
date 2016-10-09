#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	// *号可以用作可变参数，来进一步控制格式
	{
		double a = 0.12345612345678987654321;

		for (int i = 0; i < 15; ++i)
		{
			printf("%.*lf\n", i, a);
		}
	/*	0
		0.1
		0.12
		0.123
		0.1235
		0.12346
		0.123456
		0.1234561
		0.12345612
		0.123456123
		0.1234561235
		0.12345612346
		0.123456123457
		0.1234561234568
		0.12345612345679*/
	}
	{
		//增量打出字符串
		char str[100] = "asndengejkgj1235";
		for (int i = 1; i <= strlen(str); ++i)
		{
			printf("%.*s\n", i, str); //%.ns，截取字符串前n位输出
		}
	}

}