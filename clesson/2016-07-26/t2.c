
#include <stdio.h>

int main(void)
{
	int sum  ; 

	int i , j;
	for(i = 2 ; i <= 1000 ; i++)
	{
		sum = 1 ; 
		for(j = 2 ; j <= i/2 ; j++)
		{
			if(i % j == 0)
				sum += j ; 
		}
		if(sum == i)
			printf(" %d  " , sum);
	}

	putchar('\n');


	return 0 ; 
}


