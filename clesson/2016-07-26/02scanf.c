
#include <stdio.h>

int main(void)
{

	long number ; 
	int a ;
	number = (long)&a ; 
	
	scanf("%d" , &a);//number);
	printf("number:%ld  a:%d \n" , number , a);

	return 0 ; 
}
