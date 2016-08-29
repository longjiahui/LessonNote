
#include <stdio.h>

//冒泡排序

int main(void)
{
	int array[10] = {4,3,2,5,6,1,7,9,8,10};

	int i  , j; 
	int tmp ; 
	
	for(i = 0 ; i < NR(array)-1 ; i++)
	{
#if 0
		for(j = 0 ; j < NR(array)-1 ; j++)
		{
			if(array[j] < array[j+1])
			{
				tmp = array[j];
				array[j]=array[j+1];
				array[j+1]=tmp ; 
			}
		}
#endif
#if 1
		for(j = 0 ;  j < NR(array)-1-i ; j++)
		{
			if(array[j] < array[j+1])
			{
				tmp = array[j];
				array[j]=array[j+1];
				array[j+1]=tmp ; 
			}
		}
#endif
	}

	for(i = 0 ; i < NR(array) ; i++)
	{
		printf("array[%d]:%d \n" , i , array[i]);
	}

	return 0 ; 
}
