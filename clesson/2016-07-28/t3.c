
#include <stdio.h>

int function(int num);

int main(void)
{
	
	printf("All Value:%d  \n" , function(5));

	return 0 ; 
}
int function(int num)
{
	if(num == 0)
		return 0;
	return (function( num - 1 )+1)*2;
}
