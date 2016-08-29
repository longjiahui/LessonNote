
#include <stdio.h>

int main(void)
{
	int array[10] = {12,2,8,22,16,4,10,6,14,20};
	int tmp[10] = {0};
	
	int count = 0 ; 
	int i ; 
	while(1)
	{
		count++ ; 
		for(i = 0 ; i < 10 ; i++)
		{
			tmp[i]=array[i]/2 ;
		}
		for(i = 1 ; i < 10 ; i++)
		{
			array[i]=tmp[i-1]+tmp[i] ;
		}
		array[0]=tmp[9]+tmp[0] ; 

		for(i = 0 ; i < 10 ; i++)
		{
			if(array[i]%2 == 1)
				array[i]+=1 ; 
		}
		for(i = 0 ; i < 10 ; i++)
		{
			if(array[i] != array[0])
				break;
		}
		if(i == 10)
		{
			printf("count:%d  value:%d \n" , count , array[0]);
			break;
		}
	}

	return 0 ; 
}
