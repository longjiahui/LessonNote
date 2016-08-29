
#include <stdio.h>

void func(int a , int b);


int main(void)
{
	int a , b ; 
	a = 100 ; 
	b = 200 ; 

	//实参
	func(a+100 , b+200);  //调用    原则:先求值,再传参
	// __LINE__  指的是程序执行时代码的行数
	// __func__  程序执行时所放的函数名字
	
	printf("%d %s a : %d  b:%d  \n" , __LINE__ , __func__ ,  a , b);
	printf("a : %p  b:%p  \n" , &a , &b);


	return 0 ; 
}
//		形参
void func(int a , int b)
{
	printf("%d %s a : %d  b:%d  \n" ,__LINE__ , __func__ , a , b);
	printf("a : %p  b:%p  \n" , &a , &b);
}
