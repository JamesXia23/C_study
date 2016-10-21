#include <iostream>
using namespace std;
class Node
{
public:
	char data;
	Node *lchild;
	Node *rchild;
	Node()
	{
		lchild = NULL;
		rchild = NULL;
	}
	Node(char data)
	{
		this->data = data;
		lchild = NULL;
		rchild = NULL;
	}
	~Node()
	{
		delete lchild;
		delete rchild;
	}
};
class BiTree
{	
public:
	Node *head;
	BiTree()
	{
		head = NULL;
	}
	void create(Node *&current)
	{
		char data;
		cin >> data;
		if(data != '0')
		{
			current = new Node(data);
			create(current->lchild);
			create(current->rchild);
		}
	}
	void preOrder(Node *current)
	{
		if (current)
		{
			cout << current->data;
			preOrder(current->lchild);
			preOrder(current->rchild);
		}
	}
	~BiTree();
};
int main(int argc, char const *argv[])
{
	BiTree tree;
	tree.create(tree.head);
	tree.preOrder(tree.head);
	return 0;
}
/*
Description
给定一颗二叉树的逻辑结构如下图，（先序遍历的结果，空树用字符‘0’表示，例如AB0C00D00），建立该二叉树的二叉链式存储结构，并输出该二叉树的先序遍历、中序遍历和后序遍历结果


Input
第一行输入一个整数t，表示有t个二叉树

第二行起输入每个二叉树的先序遍历结果，空树用字符‘0’表示，连续输入t行



Output
输出每个二叉树的先序遍历、中序遍历和后序遍历结果


Sample Input
2
AB0C00D00
AB00C00

Sample Output
ABCD
BCAD
CBDA
ABC
BAC
BCA

*/