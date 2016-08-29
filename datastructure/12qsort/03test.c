
#include <stdio.h>

void func(int *a)
{
	if (*a >= 10)
		return;
	*a += 1;
	func(a);
	printf("a = %d, &a = %p\n", *a, a);
}


int main(void)
{
	int a = 0;
	
	printf("&a = %p\n", &a);
	func(&a);

	return 0;
}
