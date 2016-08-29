
#include <stdio.h>

int main(void)
{

	//判断类型是否一致
	//如果类型一致,则返回1
	//如果类型不一致,则返回0
	
	int *array;

	printf("value:%d \n" , __builtin_types_compatible_p(int , char));
	printf("value:%d \n" , __builtin_types_compatible_p(typeof(array) , typeof(&array[0])));


	return 0 ; 
}
