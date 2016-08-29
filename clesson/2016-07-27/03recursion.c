
#include <stdio.h>

int func(int num , int sum);
int func1(int num );

int main(void)
{

	printf("sum: %d \n" , func(5 , 0));
	printf("sum: %d \n" , func1(5));

	return 0 ; 
}

int func(int num , int sum)
{
	//退出条件
	if(num == 0)
		return sum; 
	//过去
	//printf("%d \n" , num);
	sum = sum + num ;

	return func(num - 1 , sum);
	//回来


}
int func1(int num)
{
	//退出条件
	if(num == 0)
		return 0; 
	int ret ; 
	ret = func1(num - 1 ) ; 
	//回来

	return ret+num;

	//return func1(num-1)+num;
}

