
#include <stdio.h>

int function(int num , int sum);

int main(void)
{
	
	int number ; 
	scanf("%d" , &number);

	int tmp ;

	while(1)
	{
		tmp = function(number , 0);
		if(tmp == number)
		{
			printf("是回文数%d\n" , number);
			break;
		}
		printf("%15d + %15d = %20d \n" , number , tmp , number+tmp);
		number = number + tmp ; 
	}

	//printf("value:%d  \n" , function(123456 , 0));


	return 0 ; 
}

int function(int num , int sum)
{
	if(num == 0)
		return sum; 
	
	return function(num/10 , sum*10+num%10);
}
