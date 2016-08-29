
#include <stdio.h>

int main(void)
{
	int number ; 

	scanf("%d" , &number );

	while(number/10)
	{
		if((number%10+number/10)%2==0)
		{
			printf("NO \n");
			break;
		}
		number/=10;
	}

	if(number/10==0)
	{
		printf("YES \n");
	}

	return 0 ; 
}
