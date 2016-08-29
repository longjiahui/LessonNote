
#include <stdio.h>

int main(void)
{

	for(;;)
	{
		while(1)
		{
			while(1)
			{
				goto OUT ; 
			}
		}
	}
	//2.打破多层循环
OUT:
	printf("I am Out \n");

	return 0 ; 
}
