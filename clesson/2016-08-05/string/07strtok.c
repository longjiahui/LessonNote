
#include <stdio.h>
#include <string.h>

char *mystrtok(char *str , const char *delim);

int main(void)
{
	char Buffer[50] = "hello,i.am'not:good?and;you!ha";
	char *exp = ",.':?;!";

	char *p = NULL ;
	

	//p = strtok(Buffer , exp);
	p = mystrtok(Buffer , exp);
	printf("p:%s \n" , p);
	//printf("buffer:%s \n" , Buffer);

	int len = 0 ;
	//len += strlen(p)+1;
	while(1)
	{
		//p = strtok(NULL , exp);
		p = mystrtok(NULL , exp);
		if(NULL == p)
			break;
		printf("p:%s \n" , p);
	//	len += strlen(p)+1;
	//printf("buffer:%s \n" , Buffer+len);
	}


	return 0 ;
}

//不可重入的函数
char *mystrtok(char *str , const char *delim)
{
	static char *Save = NULL; 
	char *tmp = NULL ;
	char *tmp1 = NULL ; 
	if(str != NULL)
	{
		Save = str ; 
	}

	tmp = Save; 
	
	if(*tmp == '\0')
		return NULL ; 

	while(*tmp)
	{
		tmp1 = (char *)delim;
		while(*tmp1)
		{
			if(*tmp == *tmp1)
			{
				*tmp = '\0';
				tmp1=Save ; 
				Save = tmp+1 ; 
				return tmp1; 
			}
			tmp1++ ; 
		}

		tmp++ ; 
	}
	if(*tmp == '\0')
	{
		tmp1 = Save ; 
		Save = tmp ; 
		return tmp1; 
	}
}
