
#include <stdio.h>
#include <string.h>

int  mystrcmp(const char *str1 , const char *str2);

int main(void)
{
	//'A'  65 'a' 97 '0' 48
	
	char *str1 = "hello";
	char *str2 = "helloA";

	int ret ; 
	
	//ret = strcmp(str1 , str2);
	ret = mystrcmp(str1 , str2);

	printf("ret:%d  \n" , ret);


	return 0 ; 
}

int  mystrcmp(const char *str1 , const char *str2)
{
	while(*str1 == *str2)
	{
		if(*str1 == '\0')
			return 0 ;
		str1++ ; 
		str2++ ; 
	}

	return *str1 - *str2 ; 
}
