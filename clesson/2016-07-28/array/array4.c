
#include <stdio.h>

int main(void)
{
	int array[5] = {1,2,3,4,5};

	int i ;
	//int array[] ==> int *array
	for(i = 0 ; i < 5 ; i++)
	{
		//printf("array[%d]:%d \n" , i , array[i]);
		//printf("array[%d]:%d \n" , i , *(array + i));
		//printf("array[%d]:%d \n" , i , *(int *)((char *)array + i*4));
		//printf("array[%d]:%d \n" , i ,  i[array]);
	}


	return 0 ; 
}
