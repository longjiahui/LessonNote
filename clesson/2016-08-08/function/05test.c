
#include <stdio.h>

void function(int a , ...);

int main(void)
{
	
	
	function(10,20,'A');


	return 0 ; 
}

void function(int a , ...)
{
	char *p = (char *)&a ; 
	p = p + 28 ;

	printf("p:%d \n" , *(int *)p);
	
	p = p + 8;

	printf("p:%d \n" , *(int *)p);

}

