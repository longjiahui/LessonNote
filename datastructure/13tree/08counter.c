
#include <stdio.h>


int count(char *p);
int main(void)
{
	char *p = "hel";

	printf("%d\n", count(p));
	return 0;
}

int count(char *p)
{
	int c;
	if (0 == *p)
		return 0;

	c = count(p+1)+1;
	return c;
}
/*
1. count('h")
	c = count('e')+1
	...
	return 3;
	
   2. count('e')
	c = count('l')+1
	...
	return 2;

	3. count('l')
		c = count('\0')+1;
		return 1








*/
