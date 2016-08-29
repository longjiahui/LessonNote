
#include <stdio.h>

int main(void)
{
	int a ; 
	a = 100 ; 
	//int * 指针类型
	//&   取地址
	//*   取值  间接引用
	
	//int *p = &a ; 
	int *p ; 
	p = &a ; 
	
	*p = 200 ; 
	
	printf("a : %d  *p:%d  \n" , a , *p);

	return 0 ;
}
