
#include <stdio.h>
#include <string.h>

char *mystrcat(char *dest , const char *src);
char *mystrncat(char *dest , const char *src , int len);

int main(void)
{
	//char Dest[60] = "hello ";
	char Dest[60] = {'h','e','l','l','o',' ','\0','A','A','A','A','A'};
	char *src = "world";

	char *p = NULL ; 
	//字符串粘贴
	//p = strcat(Dest , src);
	//p = strncat(Dest , src , 8);
	//p = mystrcat(Dest , src);
	p = mystrncat(Dest , src , 2);

	printf("p:%s  Dest:%s  \n" ,  p , Dest);
	printf("p:%p  Dest:%p  \n" ,  p , Dest);

	return 0 ; 
}

char *mystrcat(char *dest , const char *src)
{
	char *tmp = dest ; 
	while(*dest++) 
		; //nothing
	dest-- ;
	while(*dest++ = *src++)
		; //nothing
	return tmp; 
}
	

char *mystrncat(char *dest , const char *src , int len)
{
	char *tmp = dest ; 
	while(*dest++) 
		; //nothing
	dest-- ;
	while((*dest++ = *src++) && (--len))
		; //nothing

	if(*(--dest)!='\0')
		*(++dest) = '\0';

	return tmp; 
}

