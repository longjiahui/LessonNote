
#include <stdio.h>

int main(int argc ,char *argv[] , char **environ)
{
#if 0
	int i ; 
	for(i = 0 ;i < 10 ; i++)
	{
		printf("environ[%d]:%s \n" , i , environ[i]);
	}
#endif
	char *front = NULL ;
	char *back  = NULL ; 

	while(*environ)
	{
		//**environ = 'A' ;
		//printf("eviron:%s \n" , *environ);

		//1.找到=将=置成'\0'
		front = *environ ; 
		back = front ; 	

		while(*back)
		{
			if(*back == '=')
			{
				*back = '\0';
				break;
			}
			back++ ;
		}
	
		back++ ;
		//2.判断最后一个是不是"_"
		if(strcmp(front , "_") == 0)
		{
			break;
		}

		if(strcmp(front,"D") == 0)
		{
			printf("back: %s \n" , back);
		}

		environ++ ;
	}

	return 0 ; 
}
