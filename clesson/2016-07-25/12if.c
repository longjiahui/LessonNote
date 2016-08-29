
#include <stdio.h>

int main(void)
{
	// >  <  >=  <= !=   &&  ||  !   ==  =

	int a , b , c ; 

	scanf("%d%d%d" , &a , &b , &c);
	//printf("a : %d  b : %d  c:%d  \n" , a , b , c);

	int tmp ; 

	if(a > b)
	{
		//交换
		tmp = a ; 
		a = b ; 
		b = tmp ; 
	}


	if(a > c)
	{
		tmp = a ; 
		a = c ; 
		c = tmp ;
	}

	if(b > c)
	{
		tmp = b ; 
		b = c ; 
		c = tmp ; 
	}


	printf(" %d  < %d  < %d  \n" , a , b , c);

	//if(exprssion)  //true
	//{
	//	YES
	//}else
	//{
	//	NO
	//}

	return 0 ; 
}
