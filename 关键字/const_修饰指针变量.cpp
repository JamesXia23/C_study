#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	const char *str = "hello";	//指针变量可以进行运算，但是指针指向的区域不能进行运算
	str++;
	cout << str << std::endl;	//ello
	return 0;
}
