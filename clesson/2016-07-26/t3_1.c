
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
	
	for(;;)  //默认为真  相当于死循环
	{
		if(b  %  a == 0)
		{
			printf("%d  \n" , a);
			break;
		}
		tmp = b % a ; 
		b = a ; 
		a = tmp ; 
	}


	return 0 ; 
}
