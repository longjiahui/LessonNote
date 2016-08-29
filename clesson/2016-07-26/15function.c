
#include <stdio.h>

//函数可以多次声明,但是只能实现一次
void        function(void);  //函数的声明
void        function(void);  //函数的声明  
void        function(void);  //函数的声明
//函数返回值        //函数参数

//函数返回值为int类型
int  add(int a , int b);
//函数的参数有两个  int  a  , int b  形参

int main(void)
{
	
	function();  //函数的调用

	int a = 10 ; 
	int b = 20 ; 
	//函数调用               实参  //函数的传参是先求值再传参
	printf("sum:%d  \n" , add(add(a , 20) , b));

	return 0 ;
}

void function(void)  //函数的实现
{
	printf("hello world \n");
}
//函数的实现
int  add(int a , int b)
{
	return a + b ;   //函数的返回值 
}

