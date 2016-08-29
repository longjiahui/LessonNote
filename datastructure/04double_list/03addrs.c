
#include <stdio.h>

char *func();

int main(void)
{
	char *p = NULL;

	p = func();

	printf(p); 

//	p[2] = '2';
	return 0;
}

char *func()
{
	char *l = "hello world";

	return l;
}
