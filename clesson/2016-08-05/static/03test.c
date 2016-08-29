
#include <stdio.h>

//空间分配在程序分配空间之时就已经分配了
//只初始化一次,以后的定义直接跳过

void func(void);

int main(void)
{

	int i ; 
	
	for(i = 0 ; i < 10 ; i++)
	{
		func();
	}

	//printf("a:%d \n" , a);

	return 0 ; 
}

void func(void)
{
	static int a = 0 ;  //初始化
	//a = 200 ;   //赋值
	printf("a:%d  \n" , a++);
}

