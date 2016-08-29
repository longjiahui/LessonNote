
#include <stdio.h>

int main(void)
{
	int a , b ; 
	int tmp ; 

	scanf("%d%d" , &a , &b);
	
	if(a > b)
	{
		tmp = a ; 
		a = b ; 
		b = tmp ; 
	}
	//a最小
	
	int i ; 
	for(i = a ;i > 0 ; i-- )
	{
		if((a % i == 0) && (b % i == 0))
		{
			printf("i:%d  \n" , i);
			break;
		}
	}


	return 0 ; 
}
