#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void openQQ()
{
	/**
	 * 参数：(好像不太一样)
	 * 	hwnd:Long，指定一个窗口的句柄，有时候，windows程序有必要在创建自己的主窗口前显示一个消息框 
	 * 	lpOperation:String，指定字串“open”来打开lpFlie文档，或指定“Print”来打印它
	 * 	lpFile:String，想用关联程序打印或打开一个程序名或文件名
	 * 	lpParameters:如lpszFlie是可执行文件，则这个字串包含传递给执行程序的参数
	 * 	lpDirectory:String，想使用的完整路径
	 * 	nShowCmd:Long，定义了如何显示启动程序的常数值。参考ShowWindow函数的nCmdShow参数
	 */
	ShellExecuteA(0, "open", "\"C:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe\"", 0, 0, 1);
}
void moveQQ()
{
	HWND qq = FindWindowA("TXGuiFoundation", "QQ");

	if (qq == NULL)
	{
		printf("qq is lost\n");
	}
	else
	{
		int i = 0;
		while(i < 240) 
		{
			// BOOL SetWindowPos（HWN hWnd，HWND hWndlnsertAfter,int X，int Y,int cx，int cy,UNIT．Flags）；
		    SetWindowPos(qq, NULL, 16*i, 9*i, 400, 400, 0);

		    if (i/10 % 2)
		    {
		    	// 设置窗口显示与否
		    	ShowWindow(qq, SW_HIDE);
		    }
		    else
		    {
		    	ShowWindow(qq, SW_SHOW);
		    }
			Sleep(100);
			i += 10;
		}
		//taskkill：杀死进程 /f：强制 /im：指定进程名
		system("taskkill /f /im QQ.exe");//终止qq
		printf("qq is killed\n");
	}
}
int main(int argc, char const *argv[])
{
	openQQ();
	Sleep(5000);
	moveQQ();
	return 0;
}