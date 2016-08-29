
#include <stdio.h>

void func(int **p , int *b);

int main(void)
{

	int a  , b ; 
	a = 100 ; 
	b = 200 ; 

	int *p = &a ; 
	
	//p = &b ; 

	func(&p , &b);  //p = &b ; 


	printf("a : %d  b:%d  *p:%d \n" , a , b , *p );
	return 0 ;
}

void func(int **p , int *b)
{
	*p = b ; 
}

