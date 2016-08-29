
#include <stdio.h>

int main(void)
{
	int number ,tmp; 

	scanf("%d" , &number);

	int sum = 0 ;
	tmp = number ; 
	for(;tmp;)
	{
		sum = sum * 10 + tmp%10 ; 
		tmp= tmp/ 10 ; 	
	}

	if(sum == number)
	{
		printf("是回文数\n");
	}else
	{
		printf("不是回文数\n");
	}

	printf("sum:%d \n" , sum);


	return 0 ; 
}
