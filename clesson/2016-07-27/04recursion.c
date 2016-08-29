
#include <stdio.h>

int  func(int num , int sum);

int main(void)
{

	int ret ; 
	ret = func(1234567 , 0);

	printf("ret: %d \n" , ret);

	return 0 ;
}

int  func(int num , int sum)
{

	if(num == 0)
		return sum ; 

	return  func(num/10 , sum*10+num%10);

}

