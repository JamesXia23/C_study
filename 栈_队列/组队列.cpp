#include <iostream>
#include <queue>
#include <string>
using namespace std;

void enQueue(queue<int>* groupQueue, int groupNum);
void deQueue(queue<int>* groupQueue, int groupNum);
void dispQueue(queue<int>* groupQueue, int groupNum);

int main(int argc, char const *argv[])
{
	queue<int> *groupQueue;
	int groupNum, newNum, queueLength;
	string command;

	cin >> groupNum;
	groupQueue = new queue<int>[groupNum];

	for (int i = 0; i < groupNum; ++i)
	{
		cin >> queueLength;
		for (int j = 0; j < queueLength; ++j)
		{
			cin >> newNum;
			groupQueue[i].push(newNum);
		}
	}

	cin >> command;
	while(command[0] != 'S')
	{
		if (command[0] == 'E')
		{
			enQueue(groupQueue, groupNum);
		}
		else
		{
			deQueue(groupQueue, groupNum);
		}
		cin >> command;
	}

	dispQueue(groupQueue, groupNum);
	return 0;
}
void enQueue(queue<int>* groupQueue, int groupNum)
{
	int newNum;
	cin >> newNum;

	for (int i = 0; i < groupNum; ++i)
	{
		groupQueue[i].push(-1);//队尾插入一个作为对尾标记。。。。虽然不太好
		while(groupQueue[i].front() != -1)
		{
			if (groupQueue[i].front() != newNum)
			{
				groupQueue[i].push(groupQueue[i].front());//只要不等于就去队尾
				groupQueue[i].pop();
			}
			else
			{
				groupQueue[i].pop();
				while(groupQueue[i].front() != -1)//复位
				{
					groupQueue[i].push(groupQueue[i].front());
					groupQueue[i].pop();
				}
				groupQueue[i].pop();//去掉-1
				groupQueue[i].push(newNum);
				i = groupNum;//为了退出最外层循环
				break;
			}
		}
		if (i != groupNum)//这个队列没有找到
		{
			groupQueue[i].pop();//去掉-1
		}
		
		if (i == groupNum - 1)//到了最后一个队列还没找到
		{
			groupQueue[i].push(newNum);
		}
	}
}

void deQueue(queue<int>* groupQueue, int groupNum)
{
	for (int i = 0; i < groupNum; ++i)
	{
		if (groupQueue[i].empty())
		{
			continue;
		}
		else
		{
			groupQueue[i].pop();
			break;
		}
	}
}

void dispQueue(queue<int>* groupQueue, int groupNum)
{
	for (int i = 0; i < groupNum; ++i)
	{
		if (groupQueue[i].empty())
		{
			continue;
		}
		else
		{
			while(!groupQueue[i].empty())
			{
				cout << groupQueue[i].front() << " ";
				groupQueue[i].pop();
			}
		}
	}
	cout << endl;
}


/*
Description
组队列是队列结构中一种常见的队列结构，在很多地方有着广泛应用。组队列是是指队列内的元素分组聚集在一起。组队列包含两种命令：

1、 ENQUEUE，表示当有新的元素进入队列，首先会检索是否有同一组的元素已经存在，如果有，则新元素排在同组的最后，如果没有则插入队列末尾。

2、 DEQUEUE，表示队列头元素出队

3、 STOP，停止操作

建议使用C++自带的队列对象queue，编程更方便



Input
第1行输入一个t(t<=10)，表示1个队列中有多少个组

第2行输入一个第1组的元素个数和数值

第3行输入一个第2组的元素个数和数值，

以此类推输入完n组之后，开始输入多个操作命令(<200)，例如输入ENQUEUE 100，表示把元素100插入队列

最后输入STOP，表示输入命令结束

Output
经过命令操作后队列的最终结果

Sample Input
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
STOP

Sample Output
201 202 203

*/