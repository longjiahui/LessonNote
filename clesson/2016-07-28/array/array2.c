
#include <stdio.h>

int main(void)
{

	int array[5] = {1,2,3,4,5};

	
	//地址都是一样的
	printf("&array:%p \n" , &array);
	printf("point:%p \n" , array);
	printf("&array[0]:%p \n" , &array[0]);


	return 0 ; 
}
