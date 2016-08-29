
#include <stdio.h>

int main(void)
{
	char Buffer[20] = {0};

	int year = 2016 ; 
	int month = 8 ; 
	int day = 8 ; 

	sprintf(Buffer , "%4d-%02d-%02d" , year , month , day);

	printf("Buffer:%s \n" , Buffer);

	return 0 ;
}

