
#include <stdio.h>

int main(void)
{
	//栈区      常量区/数据段    不可以修改,只读
	char *Str = "Hello world" ; 
	char Buffer[] = "Hello world" ; 


	//*Str = 'A' ;    //段错误
	*Buffer = 'A';

	printf("Str:%s Buffer:%s  \n" , Str , Buffer);


	return 0 ; 
}
