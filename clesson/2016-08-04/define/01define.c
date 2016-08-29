
#include <stdio.h>

//定义一个标志叫HELLO
#define    HELLO
//#define    AAA

int main(void)
{

	//hello world
	//注释一行
	/*
 *
 *    多行注释   不能叠加
 * */

#if 0

#endif

#if 0
else
#endif
//判断HELLO是否已经定义
//这种方法只能判断一个宏定义

//头文件避免重复包含
#ifndef  _HELLO_H
#define  _HELLO_H

//写头文件内容

#endif


//解除HELLO宏定义
#undef  HELLO

#ifdef  HELLO
	printf("YES\n");
#else
	printf("NO \n");
#endif

#ifndef HELLO
	printf("YES\n");
#else
	printf("NO \n");
#endif


//可以判断多个
//&&  ||  !(但取非必须在defined之前)
#if !(defined(HELLO) && defined(AAA))
	printf("YES\n");
#else
	printf("NO \n");
#endif


	return 0 ; 
}
