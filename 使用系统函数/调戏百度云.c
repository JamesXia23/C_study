#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int main(int argc, char const *argv[])
{
	ShellExecuteA(0, "open", "E:\\�����װ��\\yun�ƽ⣨���غ��ѹ�������̻����ɣ�\\yungj\\BaiduYunGuanjia.exe", 0, 0, 1);

	Sleep(5000);
	HWND baidu = FindWindowA("BaseGui", "��ӭʹ�ðٶ��ƹܼ�");
	if (baidu == NULL)
	{		
		system("echo baidu is lost");
	}
	else
	{
		for (int i = 0; i < 100; i+=10)
		{
			SetWindowPos(baidu, NULL, 16*i, 9*i, 400, 400, 0);
			Sleep(1000);
		}
		
	}

	
	return 0;
}