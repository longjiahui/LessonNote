
#include <stdio.h>


int main(void)
{
	int  array[10] = {1,1,1,1,1,1,1,1,1,1};

	int  i , j ; 

	for(i = 0 ; i < NR(array) ; i++)
	{
		for(j = 0 ; j < NR(array) ; j++)
		{
			if(i == j)
				continue ; 

			if(array[i] == array[j])
			{
				if(i < j)
				{
					printf("%d " , array[i]);
				}
				break;
			}
		}
	}

	putchar('\n');

	return 0 ; 
}

