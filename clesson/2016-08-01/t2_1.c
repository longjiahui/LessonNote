
#include <stdio.h>


int main(void)
{
	int array[10] = {4,3,2,5,6,1,7,9,8,10};

	int i ; 
	int tmp ; 
	int flag = 0 ; 
	
	for(i = 0 ; i < NR(array)-1 ; i++)
	{
		if(array[i]  <  array[i+1])
		{
			tmp = array[i];
			array[i]=array[i+1];
			array[i+1]=tmp;
			flag = 1 ;
		}
		if(i == (NR(array)-2))
		{
			if(flag == 0)
				break;
			i = -1 ;
			flag = 0 ;
		}
	}

	for(i = 0 ; i < NR(array) ; i++)
	{
		printf("array[%d]:%d \n" , i , array[i]);
	}

	return 0 ; 
}
