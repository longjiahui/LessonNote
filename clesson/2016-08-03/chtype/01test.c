
#include <stdio.h>
//普通传参,这种有规定参数的函数传参,就会产生隐式类型转换
void func(int a);

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

	float a = 44.44 ; 
	int b = 200; 
#if 0
	//1.
	//没有隐式类型转换
	b = (int)a;

	//隐式类型转换
	//b = a ; 

	printf("a:%f  b:%d  \n" , a , b);
#endif
	//2.
	//可变参传参不会产生隐式类型转换,普通的传参会产生隐式类型转换
	func(a);
	//int printf(const char *format, ...);
	printf("a:%d \n" , a);  //用可变参,不会产生隐式类型转换   必须手动强转
	//printf("a:%f  b:%f  \n" , a , b);

	return 0 ; 
}

void func(int a)
{
	printf("%s  %d  \n" , __func__ , a);
}
