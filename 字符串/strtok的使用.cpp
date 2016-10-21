#include <iostream>
#include <string.h>
using namespace std;
void base();
void more();
int main(int argc, char const *argv[])
{
	//base();
	// more();
	char * str = "123\0ttt";
	cout << str << endl;
	return 0;
}
void base()
{
	char str[] = "hello world heheh qieqie";
	char *p = strtok(str, " ");
	printf("%s\n", p);
	while((p = strtok(NULL, " ")))
		printf("%s\n", p);
}
void more()
{
	char str[] = "hello,. world! heheh: qieqie?";
	char *delim = " ,.!?:'";
	char *p = strtok(str, delim);
	printf("%s\n", p);
	while((p = strtok(NULL, delim)))
		printf("%s\n", p);
}
