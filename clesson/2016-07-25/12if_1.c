
#include <stdio.h>

int main(void)
{
	// >  <  >=  <= !=   &&  ||  !   ==  =

	int a , b , c ; 

	scanf("%d%d%d" , &a , &b , &c);
	//printf("a : %d  b : %d  c:%d  \n" , a , b , c);
	

	if(a > b)
	{
		a = a + b ; 
		b = a - b ; 
		a = a - b ; 
	}


	if(a > c)
	{
		a = a + c ; 
		c = a - c ; 
		a = a - c ; 
	}

	if(b > c)
	{
		b = b + c ; 
		c = b - c ; 
		b = b - c ; 
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
