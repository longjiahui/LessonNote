
#include <stdio.h>

//static int a = 100 ; 

void func(void);

int main(void)
{

	func();

	return 0 ; 
}
void func(void)
{
	int a ; 
	//static int b = 123;  //静态变量初始化时必须是常量
	static int b;  //静态变量初始化时必须是常量
	b = a ; 
	//static int b = a; 
}
