
#include <stdio.h>

int main(void)
{
	//200 也是一种常量
	int a = 200 ;

	//只读常量
	//int const b = 300 ; 
	//const int  ==>  int const
	const int b = 300 ; 
	//存储空间不变,但是具有常量特性

	//不可以改变变量的值,只能读取
	//b = 200 ; 

	printf("&a:%p   &b:%p  \n" , &a , &b);


	return 0 ; 
}


