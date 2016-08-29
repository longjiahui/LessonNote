
#include <stdio.h>

int main(void)
{
	sleep(10);

	int number ; 

	scanf("%d" , &number);

	int sum = 0 ;
	for(;number;)
	{
		sum++ ; 
		number = number / 10 ; 	
	}

	printf("sum:%d \n" , sum);


	return 0 ; 
}
