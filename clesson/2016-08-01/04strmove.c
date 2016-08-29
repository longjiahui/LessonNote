
#include <stdio.h>

void mycopy(char *Buffer , const char *p , int len);

int main(void)
{
	char *p = "hello world and hello kitty" ; 

	char Buffer[40] = {'A','A','A','A','A','A','A','A','A','A','A','A','A','A','A'};

	mycopy(Buffer , p , 10);

	printf("Buffer:%s \n" , Buffer);
	return 0 ; 
}
void mycopy(char *Buffer , const char *p , int len)
{
	while((len--) && (*Buffer++ = *p++))
		;//nothing
}
