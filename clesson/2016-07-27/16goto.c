
#include <stdio.h>

int main(void)
{
	//1.向后跳可以跳过一段代码
	//2.向前跳可以产生一个死循环


	printf("hello 1 \n");
OUT:
	printf("hello 2 \n");
	goto  OUT ; 
	printf("hello 3 \n");
	printf("hello 4 \n");
	printf("hello 5 \n");
	printf("hello 6 \n");



	return 0 ;
}
