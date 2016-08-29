

#include <stdio.h>

void func(int *a)
{
	printf("a = %p \n", a);
	printf("&a = %p \n", &a);
}

int main(void)
{
	int a = 78;

	func(&a);	

	printf("main: &a = %p\n", &a);

	return 0;
}
