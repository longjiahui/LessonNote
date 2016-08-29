
#include <stdio.h>

int main(void)
{
	//gcc math.c   -lm
	//加数学库

	int a ; 
	a = 2 ; 

	float b = sqrt(a);

	printf("b:%f \n" , b);

	return 0 ; 
}
