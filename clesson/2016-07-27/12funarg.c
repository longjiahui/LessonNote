
#include <stdio.h>

void func(int *a , int *b);

int main(void)
{

	int a  , b ; 
	a = 100 ; 
	b = 200 ; 

	func(&a , &b);


	printf("a : %d  b:%d  \n" , a , b );
	return 0 ;
}

void func(int *a , int *b)
{
	*a = 1000 ;
	*b = 2000 ; 
}
