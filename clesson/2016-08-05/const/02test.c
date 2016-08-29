
#include <stdio.h>


int main(void)
{
	int a = 200 ; 
	int b = 300 ; 

	//不可以改变指针所指向地址的值,但是可以改变指针所指向的地址
	//const int *p = &a ;    //两种写法是一样的
	//int const *p = &a ; 

	//p = &b ;
	//*p = 400 ;

	//可以改变指针所指向地址的值,但是不可以改变指针所指向的地址
	int *const p = &a ; 
	
	//p = &b ; 
	//*p = 400 ;

	//必须在初始化是定义,要不然就没有用了
	const int *const q = &a ; 
	int const *const o = &b ; 

	//q = &b ;

	printf("a:%d  *p:%d  \n" , a , *p);

	return 0 ; 
}


