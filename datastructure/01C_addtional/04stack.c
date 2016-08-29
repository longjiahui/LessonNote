
#include <stdio.h>

void func()
{
	int aa;
	
	printf("in func: %p\n", &aa);
}

int main(void)
{
	int num = 88;

	printf("in main: %p\n", &num);
	func();

	return 0;
}
