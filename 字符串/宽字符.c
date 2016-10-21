#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
	// wchar_t 代表宽字符，宽字符占1个字符，即2个字节
	// 在字符串前加L可把字符串转化为宽字符字符串
	printf("%d\n", sizeof(L"123你好")); // 1 2 3 你 好 \n 各占1一个字符
	wchar_t a = '1';
	printf("%d\n", sizeof(wchar_t)); 
	//字符集分为两种，一种是unicode字符集，宽字符
	//一种是多字节，窄字符
	
	//MessageBox随系统设定的来接收，如果系统设定为Unicode，则需要接收宽字符，如果系统设定为多字节，则需要接收窄字符
	//windows提供了TEXT函数方便迁移，他会根据函数要求对参数进行转换
	MessageBox(0, TEXT("你好天朝"), TEXT("你好世界"), 0);

	//MessageBoxA 默认接收窄字符，无视系统设置
	//MessageBoxW 默认接收宽字符，无视系统设置
	
	//声明宽字符字符串需要加L
	wchar_t str[100] = L"123";
	return 0;
}