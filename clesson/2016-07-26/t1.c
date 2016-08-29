
#include <stdio.h>

int main(void)
{

	int i , j , k , l ; 
	int count = 0 ; 
#if 0
	for(i = 4 ; i <= 7 ; i++)   //256次
	{
		for(j = 4 ; j <= 7 ; j++)
		{
			for(k = 4 ; k <= 7 ; k++)
			{
				for(l = 4 ; l <= 7 ; l++)
				{
			count++ ; 
			if((i!=j) && (i != k) && (i != l) && (j != k) && (j != l) && (k!=l))
			{
				printf("%d  %d  %d  %d \n" , i , j , k , l );
			}
				}
			}
		}
	}
	printf("count:%d \n" , count);

	for(i = 4 ; i <= 7 ; i++)   //96次
	{
		for(j = 4 ; j <= 7 ; j++)
		{
			if(i == j)
				continue ; 
			for(k = 4 ; k <= 7 ; k++)
			{
				if((i == k) || (k == j))
					continue ; 
				for(l = 4 ; l <= 7 ; l++)
				{
			count++ ; 
			if((i != l) && (j != l) && (k!=l))
			{
				printf("%d  %d  %d  %d \n" , i , j , k , l );
			}
				}
			}
		}
	}
	printf("count:%d \n" , count);
#endif
	//时间复杂度  空间复杂度 
	
	for(i = 4 ; i <= 7 ; i++)   //48次
	{
		for(j = 4 ; j <= 7 ; j++)
		{
			if(i == j)
				continue ; 
			for(k = 4 ; k <= 7 ; k++)
			{
			count++ ; 
			if((i != k) && (k != j)) 
			{
				printf("%d  %d  %d  %d \n" , i , j , k , 22-i-j-k );
			}
			}
		}
	}
	printf("count:%d \n" , count);

	return 0 ; 
}
