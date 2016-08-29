
#include <stdio.h>

int count = 0 ; 
//栈大小   12M
//栈壁     16B

void function(void);

int main(void)
{

	function();

	return 0 ; 
}

void function(void)
{
	char buffer[5120];
	printf("count:%d \n" , count++);
	function();
}


