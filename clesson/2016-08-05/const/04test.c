
#include <stdio.h>

int main(void)
{
	//字符串常量  属于常量区,有空间.
	char *Str = "hello world" ; 
	//*Str = 'A' ;

	"" ; //本身就是一个指针,指向常量区的空间

	//"hello world"[0]='A' ;
	
	//如果说字符串常为一致时,只会分配一次
	printf("address:%p  :%c \n" , "hello world" , "hello world"[3]);
	printf("address:%p  :%c \n" , Str , Str[3]);

	return 0 ; 
}
