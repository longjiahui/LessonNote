
#include <stdio.h>
#include <string.h>

int mystrlen(const char *str);

//strlen   算出字符串的长度不包括'\0'

int main(void)
{

	char *str = "hello world and hello kitty \n";

	//printf("strlen:%d \n" ,  strlen(str));
	printf("strlen:%d \n" ,  mystrlen(str));

	return 0 ; 
}

int mystrlen(const char *str)
{
	int len = 0 ; 
	while((*str++) && (++len))
		;  //nothing
	return  len; 
}

