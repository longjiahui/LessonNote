

#include <stdio.h>
#include <string.h>

int myatoi(const char *str);

int main(int argc , char *argv[])
{

	if(argc != 2)
	{
		fprintf(stderr , "Argument Error !\n");
		return -1 ; 
	}

	//2016-08-08
	printf("date:%s \n" , argv[1]);

	int year , month , day ; 

	//int sscanf(const char *str, const char *format, ...);
	//sscanf(argv[1] , "%d-%d-%d" , &year , &month , &day);
	
	char *ret = NULL ;

	ret = strtok(argv[1] , "-");
	
	printf("ret:%s \n" , ret);
	//year = myatoi(ret);
	year = atoi(ret);

	ret = strtok(NULL , "-");
	printf("ret:%s \n" , ret);
	//month=myatoi(ret);
	month=atoi(ret);

	ret = strtok(NULL , "-");
	printf("ret:%s \n" , ret);
	//day=myatoi(ret);
	day=atoi(ret);

	printf("year:%d  month:%d  day:%d \n" , year , month , day);

	return 0 ; 
}

int myatoi(const char *str)
{
	int value = 0 ; 
	while(*str)
	{
		if((*str >= '0') && (*str <= '9'))
		{
			value = value * 10 + (*str - '0');
		}
		else
			break;
		str++ ;
	}

	return value ; 
}
