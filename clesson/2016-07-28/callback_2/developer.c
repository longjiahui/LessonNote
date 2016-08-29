
#include "developer.h"

//告诉别人,当前的Buffer只在该文件使用
static char Buffer[20] = {0}; 

int  Do_Encrypt( CALLBACK_T func )
{
	//字符串   很多个字符合在一起,但是结尾必须为'\0'
	char *p = "Hello world" ; 
	//加密
	func(p , Buffer , strlen(p));

	printf("before p:%s   \n" , p);
	printf("After Buffer:%s \n" , Buffer);
	
	return 0 ;
}

int Do_Descrypt( CALLBACK_T  func)
{
	char Result[20] = {0};

	func(Buffer , Result , strlen(Buffer));

	printf("Buffer:%s \n" , Buffer);
	printf("Result:%s \n" , Result);
	
	return 0 ;
}

