
#include <stdio.h>

void function(const int *a);

int main(void)
{

	int a = 100 ;
	
	function(&a);

	printf("a:%d \n" , a);

	return 0 ;
}

void function(const int *a)
{
	int b = 300 ;
	//*a = 200 ; 
	a = &b ; 
}
