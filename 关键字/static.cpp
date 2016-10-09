#include <iostream>

using namespace std;
static int a = 2;
void foo();
int main(int argc, char *argv[]) {
	foo();
	foo();
	
	return 0;
}
void foo(){
	static int b;
	printf("%d\n", b);
	b = 3;
	printf("%d\n", b);
}