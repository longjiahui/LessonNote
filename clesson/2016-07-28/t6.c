
#include <stdio.h>

int function(int num);

int main(void)
{
	int i ; 
	for(i = 100 ; i <= 999 ; i++)
	{
		if(i == function(i))
		{
			printf("%d   \n" , i);
		}
	}

	return 0 ; 
}

int function(int num)
{
	if(num == 0)
		return 0 ; 
	int ret ; 
	ret = function(num/10);

	return ret + (num%10)*(num%10)*(num%10);
}
