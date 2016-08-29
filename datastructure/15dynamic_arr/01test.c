
#include <stdio.h>


int main(void)
{
	// int num[10];
	int *num;
	num = malloc(sizeof(int)*10);

	free(num);
	
	num = malloc(sizeof(int)*20);  // num[20]	
	num[2] = 888;  // *(num+2)

	return 0;
}
