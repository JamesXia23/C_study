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
		system("echo ������");
	}
	else
	{
		//���ñ���
		//SetWindowTextA(win,"������");

		//������Ϣ�رմ���
		/*char cmd[100];
		for (int i = 0; i < 5; i++)
		{
			sprintf(cmd, "echo �������%d���ر�", 5 - i);
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
		system("echo �ֲ�����");
	}
	else
	{
		for (int i = 65; i < 130; i++)
		{
			//SendMessageA(zi, WM_CHAR, i, 0);//ͬ��
			PostMessageA(zi, WM_CHAR, i, 0);//�첽
			Sleep(100);
		}
	}
}
void button_process(HWND zi)
{
	if (zi == NULL)
	{
		system("echo zi ������");
	}
	else
	{
		system("echo zi ������");
		SetWindowTextA(zi, "��å��ť");//���ð�ť����
		Sleep(2000);
		//SendMessageA(zi, WM_CLOSE, 0, 0);���ر���Ϣ
		//SendMessageA(zi, BM_CLICK, 0, 0);�������Ϣ
		//ShowWindow(zi, SW_HIDE);//����/��ʾ����
		//Sleep(5000);
		//ShowWindow(zi, SW_SHOW);
		//EnableWindow(zi, 0);//���ð�ť
		//Sleep(5000);
		//EnableWindow(zi, 1);//�ָ���ť
	}
}