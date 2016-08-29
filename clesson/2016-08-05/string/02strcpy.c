
#include <stdio.h>
#include <string.h>

char *mystrcpy(char *dest , const char *src);

int main(void)
{
	//strcpy
	char *str = "hello world";
	char *p = NULL;  //当前的指指向没有空间
	
	//碰到未知大小的数组,申请足够大的空间
	//动态数组

	char Buffer[50];

	//将内存空间充满某个字符
	memset(Buffer , 'A' , 50);
	//字符串复制,且有带'\0'
	
	//p = strcpy(Buffer , str);
	p = mystrcpy(Buffer , str);

	printf("Buffer:%s p:%s \n" , Buffer , p);
	printf("Buffer:%p p:%p \n" , Buffer , p);

	return 0 ; 
}


char *mystrcpy(char *dest , const char *src)
{
	char *tmp = dest ; 
	while(*dest++ = *src++)
		;//nothing
	return tmp;
}



