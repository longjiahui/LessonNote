
#include <stdio.h>

int main(void)
{

	int array[5] = {1,2,3,4,5};

	//只要数组出现偏移,就表现指针特性
	printf("size:%d  \n" , sizeof(array));
	printf("size:%d  \n" , sizeof(array+0));

	//int *array[5] ; 
	//int (*array)[5] ; 

	return 0 ; 
}
