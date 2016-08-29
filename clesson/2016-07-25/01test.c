
#include <stdio.h>
//stdio    standard  input and  output   标准输入输出头文件

//  两个/为注释   注释当前行
//编译   gcc  01test.c    生成   a.out
//执行   ./a.out

//全局区
int a = 200 ;   //全局变量   变量的定义
int c  ;   //变量的声明


//main函数  
int main(void)
{
	//局部区域
	int b = 300 ; 
	//局部变量

	printf("hello world \n");


	//返回值
	return 0 ; 
}

