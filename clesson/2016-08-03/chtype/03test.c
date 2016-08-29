
#include <stdio.h>

int main(void)
{
	//当signed 与unsigned 进行运算时,会产生隐式类型转换
	//将signed 转换成 unsigned 再进行运算
	
	int a = -10 ; 
	unsigned int b = 8 ; 
	//unsigned int b = 12 ; 
	//int c = a + b ; 
	unsigned int c = a + b ; 
	printf("sum:%u\n" ,a+b );
	printf("%s \n" , (a + b > 0)?"YES":"NO");

	return 0 ;
}
