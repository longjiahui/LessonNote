
#include <stdio.h>

void func(int num);

int main(void)
{

	func(5);

	return 0 ; 
}

void func(int num)
{
	//退出条件
	if(num == 0)
		return ; 
	

	func(num - 1);

	printf("%d \n" , num);


}
