
#include <stdio.h>

//只是替换   宏定义
#define   AA   int

//类型定义
typedef   unsigned long  U64 ;
typedef   unsigned int   U32 ;
typedef   unsigned short U16 ; 
typedef   unsigned char  U8  ; 

//函数指针的类型定义

int add(int a , int b);
int sub(int a , int b);

typedef   int (func_t)(int , int );  //类型定义一个函数类型
typedef   int (*Func_t)( int,int );  //类型定义一个函数指针类型

int main(void)
{
	
	AA  a ; 
	U32 b ; 
	unsigned int c ; 

	func_t * ADD = add ; 
	Func_t  SUB  = sub ; 

	printf("sum:%d \n" , ADD(10 , 20));
	printf("sum:%d \n" , SUB(20 , 10));

	return 0 ;
}
int add(int a , int b)
{
	return a + b ; 
}
int sub(int a , int b)
{
	return a - b ; 
}

