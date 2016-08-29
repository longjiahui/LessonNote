
#include <stdio.h>
#include <stdarg.h>

//函数的可变参
void func(int a , ...);

int main(void)
{
	
	
	func(10,20,30,'A',33.33,"hello",44);


	return 0 ; 
}

void func(int a , ...)
{

	printf("func:%d \n" , a);

//void va_start(va_list ap, last);
//type va_arg(va_list ap, type);
//void va_end(va_list ap);

	va_list ap ; 
	//last 最后一个,离...最近的一个
	va_start(ap , a);

	int ret ; 
	ret = va_arg(ap , int);
	printf("ret:%d \n" , ret);

	ret = va_arg(ap , int);
	printf("ret:%d \n" , ret);

	char ch ; 
	ch = va_arg(ap , int); //char==>int
	printf("ch:%c \n" , ch);

	double f ; 
	f = va_arg(ap , double);
	printf("float:%lf \n" , f);

	char *str = NULL; 
	str = va_arg(ap , char *);
	printf("str:%s \n" , str);

	ret = va_arg(ap , int);
	printf("ret:%d \n" , ret);

	va_end(ap);
}
