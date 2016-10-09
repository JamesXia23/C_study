#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	char *p = "beautiful";
	char *q = "beau";
	cout << *++q << endl;//先进行++，再执行*，此时++q，表达式值为指向e，q的值也指向e
	cout << *p++ << endl;//先进行++，再执行*，此时p++，表达式值为指向b，q的值++指向e

	return 0;
}