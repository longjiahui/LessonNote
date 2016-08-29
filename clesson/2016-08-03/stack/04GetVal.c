
#include <stdio.h>

int *function(void);

int main(void)
{
	int *p = NULL ;
	
	p = function();
	
//	printf("hello world \n");

	printf("*p:%d *p+1:%d *p+2:%d \n" , *p , *(p+1) , *(p+2));

	return 0 ; 
}


int *function(void)
{

	int a = 100; 
	int b = 200; 
	int c = 300; 

	//printf("&a:%p &b:%p &c:%p \n" , &a , &b , &c);

	return &b ; 
}

