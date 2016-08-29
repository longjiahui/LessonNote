
#include <stdio.h>
#include <string.h>

char *mystrstr(const char *haystack , const char *needle);

int main(void)
{
	char *str = "hello dog and pig and hotdog" ;
	char *needle = "pig" ;

	char *p = NULL ; 

	//p = strstr(str , needle);
	p = mystrstr(str , needle);

	printf("p:%s \n" , p);

	return 0 ; 
}

char *mystrstr(const char *haystack , const char *needle)
{
	char *tmp = NULL;
	char *tmp1 = NULL ;
	while(*haystack)
	{
		tmp = (char *)haystack ; 
		tmp1 = (char *)needle ; 

		while(1)
		{
			if(*tmp1 == '\0')
				return (char *)haystack ; 

			if(*tmp1 != *tmp)
				break;

			tmp1++ ; 
			tmp++ ; 
		}

		haystack++ ;
	}
	return NULL ; 
}

