
#include <stdio.h>

int function(int num);

int main(void)
{
	//过去
	int sum ; 
	sum = function(100);

	printf("sum:%d \n" , sum);

	return 0 ; 
}

int function(int num)
{
	if(num == 0)
		return   0;
	return function(num - 1)+num;
}
