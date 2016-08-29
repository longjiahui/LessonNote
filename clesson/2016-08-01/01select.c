
#include <stdio.h>

//选择排序


int main(void)
{
	int array[10] = {4,3,2,5,6,1,7,9,8,10};

	int i  , j; 
	int tmp ; 
	
	for(i = 0 ; i < NR(array)-1 ; i++)
	{
		for(j = i+1 ; j < NR(array) ; j++)
		{
			if(array[i] > array[j])
			{//从小到大
				tmp = array[i];
				array[i]=array[j];
				array[j]=tmp ; 
			}
		}
	}

	for(i = 0 ; i < NR(array) ; i++)
	{
		printf("array[%d]:%d \n" , i , array[i]);
	}

	return 0 ; 
}
