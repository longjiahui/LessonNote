
#include <stdio.h>

int main(void)
{
	int i , j , k ; 

#if 0
	for(i = 0 ; i <= 20 ; i++)
	{
		for(j = 0 ; j <= 33 ; j++)
		{
			for(k = 0 ; k <=100 ; k+=3)
			{
		if((i + j + k == 100) && (i*5+j*3+k/3 == 100))
			printf("%d  %d  %d  \n" , i , j , k);
			}
		}
	}
#endif
	for(i = 0 ; i <= 20 ; i++)
	{
		for(j = 0 ; j <= 33 ; j++)
		{
		//if((i*5+j*3+(100-i-j)/3 == 100) && ((100-i-j)%3==0))
		if(i*5*3+j*3*3+(100-i-j) == 300)
			printf("%d  %d  %d  \n" , i , j , k);
		}
	}




	return 0 ; 
}

