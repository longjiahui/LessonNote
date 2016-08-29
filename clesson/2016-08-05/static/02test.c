
#include <stdio.h>

//空间分配在程序分配空间之时就已经分配了

int flag = 1 ; 

void func(void);

int main(void)
{

	func();
	printf("helo \n");
	func();
	printf("helo \n");
	func();
	printf("helo \n");
	

	return 0 ; 
}

void func(void)
{
	static int a  ;
	if(flag == 1)
	{
		a = 200 ;
		flag = 0 ; 
	}
	printf("a:%d  \n" , a);
}

