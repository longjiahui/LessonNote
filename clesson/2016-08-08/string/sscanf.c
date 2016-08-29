

#include <stdio.h>

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
	sscanf(argv[1] , "%d-%d-%d" , &year , &month , &day);
	

	printf("year:%d  month:%d  day:%d \n" , year , month , day);

	return 0 ; 
}
