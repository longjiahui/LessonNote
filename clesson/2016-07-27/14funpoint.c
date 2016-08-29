
#include <stdio.h>

//0x4003c0  printf函数
//函数指针定义
int (*ppp)(const char *fmt , ...) = (void *)0x4003C0;

int main(void)
{
	//main   函数指针
	
	((int (*)(const char * , ...))(0x4003C0))("hello kitty \n");  //常指针

	ppp("hello world \n");
	printf("printf:%p \n" , printf);

	return 0 ; 
}
