
#include <stdio.h>

int main(void)
{

	srand(time(NULL));
	int i ;
	for(i = 0 ; i < 10 ; i++)
	{
		int random = rand();
		printf("random:%d \n" , random);
	}





	return 0 ; 
}

