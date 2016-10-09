#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int t,n;
	int num;
	string commands, command;

	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> commands;
		if(commands[2] == 'F')
		{
			queue<int> q;
			for (int i = 0; i < n; ++i)
			{
				cin >> command;
				if(command[0] == 'I')
				{
					cin >> num;
					q.push(num);
				}
				else
				{
					if (q.empty())
					{
						cout << "None" << endl;
					}
					else
					{
						cout << q.front() << endl;
						q.pop();
					}
				}
			}
		}
		else
		{
			stack<int> s;
			for (int i = 0; i < n; ++i)
			{
				cin >> command;
				if(command[0] == 'I')
				{
					cin >> num;
					s.push(num);
				}
				else
				{
					if (s.empty())
					{
						cout << "None" << endl;
					}
					else
					{
						cout << s.top() << endl;
						s.pop();
					}
				}
			}
		}
	}
	return 0;
}


/*
Description

ACboy被人绑架了！ 
他非常想念他的母亲。你无法想象他被关在一个有多么黑暗的房间里。 
作为一个聪明的ACMER，你想从怪物labyrinth中把ACboy拯救出来。当你来到迷宫的门口，labyrinth怪物说：“听说你很聪明，但我提出的问题你绝对解决不了，你将和ACboy一起over。”
怪物的题目就在墙壁上。
每个问题的第一行是一个数字N，（命令的个数），近接着是一个单词“FIFO”或“FILO”。（很幸运，因为你知道“FIFO”，代表为“先进先出”，和“FILO”的意思是“先进后出”）。
 
接下来的下N行，每行是“IN M”或“OUT”，（M代表一个整数）。 
每个问题的答案就是当前门的password，所以如果你想拯救ACboy，认真回答问题！
Input

输入有多组测试数据

第一行一个整数，代表测试数据的组数。

每个子问题的输入在问题描述中已给出。

Output

对每一个“OUT”命令，需要根据”FIFO“或”FILO“，输出一个整数，如果没有任何数，输出”NONE“

Sample Input

4
4 FIFO
IN 1
IN 2
OUT
OUT
4 FILO
IN 1
IN 2
OUT
OUT
5 FIFO
IN 1
IN 2
OUT
OUT
OUT
5 FILO
IN 1
IN 2
OUT
IN 3
OUT
Sample Output

1
2
2
1
1
2
None
2
3
*/
