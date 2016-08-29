
#include "developer.h"


void Do_Calculate(int (*calculate)(int , int ))
{
	int a ;
	int b ; 
	a = 100 ; 
	b = 5 ; 

	int sum ; 
	sum = calculate(a , b );
	
	printf("sum: %d  \n" , sum);
}


