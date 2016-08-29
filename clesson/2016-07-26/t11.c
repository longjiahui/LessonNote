
#include <stdio.h>

int main(void)
{
	int i ; 
	int tmp ; 
	for(i = 0 ; i < 1000 ; i+=3)
	{	
		tmp = i ; 
		for(;tmp;)
		{
			if(tmp % 10 == 5)
				break;
			tmp = tmp/10 ; 
		}
		if(tmp)
			printf(" %d  " , i);
	}
	putchar('\n');


	return 0 ; 
}
