
#include <stdio.h>

void func2(void);
void func1(void);


int main(void)
{

	printf("hello 1 \n");
	func1();
	printf("hello 5 \n");

	return 0 ; 
}

void func1(void)
{
	printf("hello 2 \n");
	func2();
	printf("hello 3 \n");
}
void func2(void)
{
	printf("hello 4 \n");
}
