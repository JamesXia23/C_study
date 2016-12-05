#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

void button_process(HWND zi);
void edit_process(HWND zi);
void main()
{
	HWND win = FindWindowA("#32770", "message");

	if (win == NULL)
	{	
		system("echo 不见了");
	}
	else
	{
		//设置标题
		//SetWindowTextA(win,"哈哈哈");

		//发送消息关闭窗口
		/*char cmd[100];
		for (int i = 0; i < 5; i++)
		{
			sprintf(cmd, "echo 软件将在%d秒后关闭", 5 - i);
			system(cmd);
			Sleep(1000);
		}
		
		SendMessageA(win, WM_CLOSE, 0, 0);*/

		/*HWND zi = FindWindowExA(win, 0, "Button", "Button1");
		button_process(zi);*/

		HWND zi = FindWindowExA(win, 0, "Edit", "");
		edit_process(zi);

	}
	system("pause");
}
void edit_process(HWND zi)
{
	if (zi == NULL)
	{
		system("echo 又不见了");
	}
	else
	{
		for (int i = 65; i < 130; i++)
		{
			//SendMessageA(zi, WM_CHAR, i, 0);//同步
			PostMessageA(zi, WM_CHAR, i, 0);//异步
			Sleep(100);
		}
	}
}
void button_process(HWND zi)
{
	if (zi == NULL)
	{
		system("echo zi 不见了");
	}
	else
	{
		system("echo zi 出现了");
		SetWindowTextA(zi, "流氓按钮");//设置按钮文字
		Sleep(2000);
		//SendMessageA(zi, WM_CLOSE, 0, 0);发关闭消息
		//SendMessageA(zi, BM_CLICK, 0, 0);发点击消息
		//ShowWindow(zi, SW_HIDE);//隐藏/显示窗口
		//Sleep(5000);
		//ShowWindow(zi, SW_SHOW);
		//EnableWindow(zi, 0);//禁用按钮
		//Sleep(5000);
		//EnableWindow(zi, 1);//恢复按钮
	}
}