
#include <stdio.h>

void func()
{
	int a, b;

	printf("a = %d, b = %d\n", a, b); 
}

void func2()
{
	int aa = 333, bb = 444;
}


int main(void)
{	
	func2();
	
	func();
	return 0;
}
