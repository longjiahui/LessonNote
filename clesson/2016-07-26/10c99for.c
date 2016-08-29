
#include <stdio.h>

int main(void)
{


	int sum = 0 ; 
	//这种方法是C99的方法
	//如果想用C99方法 必须要编译时加  gcc xxx.c  -std=c99  / -std=gnu99
	for(int i = 0 ; i <= 100 ; i++)
	{//局部的i 外部找不到
		sum += i ; 
	}

	printf("sum:%d \n" , sum);

	return 0 ; 
}
