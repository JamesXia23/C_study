#include <Windows.h>
#include <stdio.h>

int main()
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

		HWND zi = FindWindowExA(win, 0, "Button", "Button1");
		if (zi == NULL)
		{	
			system("echo zi 不见了");
		}
		else
		{
			system("echo zi 出现了");
			SetWindowTextA(zi, "流氓按钮");
			SendMessageA(zi, WM_CLOSE, 0, 0);
		}
	}
	return 0;
}