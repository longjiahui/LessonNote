
#include <stdio.h>
#include <stdlib.h>

void exit0(void);

void func()
{
	exit(0);
}

int main(void)
{
	atexit(exit0);

	printf("main end\n");
	func();	
	printf("main end222\n");

	return 0;
}


void exit0(void)
{
	printf("in exit ...\n");
}
