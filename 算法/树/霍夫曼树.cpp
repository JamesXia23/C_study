// n个叶子结点的Huffman树共2n-1个结点
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

struct HuffmanNode
{
	char data;		//数值
	int weight;		//权值
	int parent;		//父节点
	int lchild;		//左孩子
	int rchild;		//右孩子
	bool isChosen;
	char code[100];
}* huff;

void createHuffTree(char *str);
void generateHuffCode(int length);
int main(int argc, char const *argv[])
{
	char str[100];
	scanf("%s", str);

	createHuffTree(str);
	generateHuffCode(strlen(str));

	return 0;
}

void createHuffTree(char *str)
{
	int length = strlen(str);
	huff = new struct HuffmanNode[2*length-1];

	/**
	 * 初始化叶子节点
	 */
	for (int i = 0; i < length; ++i)
	{
		huff[i].data = str[i];
		huff[i].lchild = -1;
		huff[i].rchild = -1;
		huff[i].isChosen = false;
		scanf("%d", &huff[i].weight);
	}

	/**
	 * 建树
	 */
	for (int i = length; i < 2*length-1; ++i)
	{
		int min1, min2;//用来存放最小的两个节点下标
		for (int j = 0; j < i; ++j)//寻找第一个未选择过的节点
		{
			if (!huff[j].isChosen)
			{
				min1 = j;
				break;
			}
		}
		for (int j = min1+1; j < i; ++j)//寻找第二个未选择过的节点
		{
			if (!huff[j].isChosen)
			{
				min2 = j;
				break;
			}
		}

		//从index开始更新最小值
		int index = min2 + 1;
		//保持最小值下标为min1
		huff[min2].weight < huff[min1].weight ? (min1 = min1^min2, min2 = min1^min2, min1 = min1^min2) : 1;
		for (int j = index; j < i; ++j)
		{
			if (!huff[j].isChosen && huff[j].weight < huff[min2].weight)
			{
				min2 = j;
				huff[min2].weight < huff[min1].weight ? (min1 = min1^min2, min2 = min1^min2, min1 = min1^min2) : 1;
			}
		}
		huff[min1].isChosen = true;
		huff[min1].parent = i;
		huff[min2].isChosen = true;
		huff[min2].parent = i;
		huff[i].lchild = min1;
		huff[i].rchild = min2;
		huff[i].parent = -1;
		huff[i].weight = huff[min1].weight + huff[min2].weight;
	}

	/*for (int i = 0; i < 2*length-1; ++i)
	{
		printf("%d  %d  %d  %d  %d\n", huff[i].weight, huff[i].parent, huff[i].lchild, huff[i].rchild, huff[i].isChosen);
	}*/
}

void generateHuffCode(int length)
{
	stack<char> s;
	for (int i = 0; i < length; ++i)
	{
		int temp = i;
		while(huff[temp].parent != -1) {
			int p = huff[temp].parent;
			temp == huff[p].lchild ? s.push('0') : s.push('1');
		    temp = p;
		}
		int j = 0;
		while(!s.empty()) {
		    huff[i].code[j++] = s.top();
		    s.pop();
		}
		huff[i].code[j++] = '\0';
		printf("%s\n", huff[i].code);
	}
}