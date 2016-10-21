#include <stdio.h>
#include <stdlib.h>
#include <locale.h>	//本地化头文件

int main(int argc, char const *argv[])
{
	//没有生效，还是输不出中文
	setlocale(LC_ALL, "zh-CN");//设置语言环境为中文
	
	wchar_t wstr[10] = L"你好";
	wprintf(L"%ls", wstr);

	return 0;
}