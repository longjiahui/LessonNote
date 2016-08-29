
#include <stdio.h>

int main(void)
{
	// -Wall  输出所有的错误及警告
	
	int a = 100 ; 
	int array[5] = {1,2,3,4,5};
	int b = 200 ; 
	//数组的越界不会被编译器检查
	//越界首先会先修改栈内变量,如若严重会发生段错误
	array[5] = 300 ; 
	array[6] = 400 ; 
	array[7] = 500 ; 
	array[8] = 600 ; 

//	int i ; 
//	for(i = 5 ;  ; i++)
//	{
//		array[i] = i*100 ; 
//		printf("array:%d \n" , i);  //段错误
//	}

	//数组的地址是连续的,且每一个元素相差4个字节,跟数组的类型有关系
	for(i = 0 ; i < 5 ; i++)
	{
		printf("array[%d]:%p \n" ,  i , &array[i]);
	}

	printf("a:%d b:%d \n" , a , b);

	return 0 ; 
}
