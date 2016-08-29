
#include <stdio.h>


void func(int a)
{
	if (a >= 10)
		return;	


	func(a+1);
	printf("in func: a = %d\n", a);

	getchar();
}

int main(void)
{
	func(0);
	return 0;
}
