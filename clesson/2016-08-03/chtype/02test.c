
#include <stdio.h>
//普通传参,这种有规定参数的函数传参,就会产生隐式类型转换
int func(void);
float function(void);

int main(void)
{
	//强转(手动)
	//float a = 44.4 ; 
	//int b = (int)a ;   //将不同的类型直接转换

	//隐式类型转换(自动)    //往大转
	//1.只要出现赋值,就有可能出现隐式类型转换
	//2.函数传参
	//3.返回值
	//4.操作符运算

	int a  ; 
	float b ; 
	
	a = func();
	b = func();

	int c  ; 
	c = function();
	
	printf("a:%d \n" , a);
	printf("b:%f \n" , b);
	printf("c:%d \n" , c);

	return 0 ; 
}

int func(void)
{
	float a = 33.33 ; 

	//在返回时产生隐式类型转换
	return a ; 
}

float function(void)
{
	float b = 33.44 ; 
	return b ; 
}
