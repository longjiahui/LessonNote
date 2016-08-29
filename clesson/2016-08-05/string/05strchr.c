
#include <stdio.h>
#include <string.h>

char *mystrchr(const char *str , int ch);
char *mystrrchr(const char *str , int ch);

int main(void)
{
	char *str = "hello dog";

	char *p = NULL ; 
	//如果查找不到该字符返回NULL
	//从字符串第一个开始查找,找到该字符之后,返回该字符的地址
	//p = strchr(str , 'l');
	//p = mystrchr(str , 'd');
	//从字符串最后一个开始查找,找到该字符之后,返回该字符的地址
	//p = strrchr(str , 'a');
	p = mystrrchr(str , 'l');

	printf("p:%s \n" , p);

	return 0 ; 
}

char *mystrchr(const char *str , int ch)
{
	char *tmp = NULL; 
	while(*str)
	{
		if(*str == ch)
		{
			tmp =(char *)str ; 
			break;
		}
		str++ ;
	}

	return tmp ; 
}

char *mystrrchr(const char *str , int ch)
{
	char *tmp = NULL; 
	while(*str)
	{
		if(*str == ch)
			tmp =(char *)str ; 
		str++ ;
	}

	return tmp ; 
}
