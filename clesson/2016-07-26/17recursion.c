
#include <stdio.h>

int function(int num , int sum);

int main(void)
{
	//过去
	int sum ; 
	sum = function(100 , 0);

	printf("sum:%d \n" , sum);

	return 0 ; 
}

int function(int num , int sum)
{
	if(num == 0)
		return  sum ;
	return function(num - 1 , sum+num);
}

