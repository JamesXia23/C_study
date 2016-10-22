#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void openThunder()
{
    ShellExecuteA(0, "open", "\"C:\\Program Files (x86)\\Thunder Network\\Thunder\\Program\\Thunder.exe\"", 0, 0, 1);
}
int main(int argc, char const* argv[])
{
	system("taskkill /f /im Thunder.exe");
	Sleep(2000);
	openThunder();
	// system("\"C:\\Program Files (x86)\\Thunder Network\\Thunder\\Program\\Thunder.exe\" -StartType:StartMenu & start");
	Sleep(5000);
	HWND thunder = FindWindowA("XLUEFrameHostWnd", "Ñ¸À×¼«ËÙ°æ");
	// HWND thunder = (HWND)0x00121398;
	if(!thunder) {
		printf("thunder is lost\n");
	}
	else {
		char cmd[100];
		for (int i = 0; i < 20; ++i)
		{
			sprintf(cmd, "title \"%d seconds\"", i);
			Sleep(1000);
			system(cmd);
			if (i % 2)
			{
				ShowWindow(thunder, SW_HIDE);
				continue;
			}
			ShowWindow(thunder, SW_SHOW);
		}
	}
	system("taskkill /f /im Thunder.exe");
    return 0;
}