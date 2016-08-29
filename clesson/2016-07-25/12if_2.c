
#include <stdio.h>

int main(void)
{
	// >  <  >=  <= !=   &&  ||  !   ==  =

	int a , b , c ; 

	scanf("%d%d%d" , &a , &b , &c);
	//printf("a : %d  b : %d  c:%d  \n" , a , b , c);
	
	//如果a最大
	if( (a > b)  &&  (a > c))
	{
		if(b > c)
			printf(" %d  <  %d < %d \n" , c ,  b , a);
		else
			printf(" %d  <  %d < %d \n" , b ,  c , a);
	}

	if( (b > a) && (b > c))
	{
		if(a > c)
			printf(" %d  <  %d < %d \n" , c ,  a , b);
		else
			printf(" %d  <  %d < %d \n" , a ,  c , b);
	}

	if((c > a) && (c > b))
	{
		if(a > b)
			printf(" %d  <  %d < %d \n" , b ,  a , c);
		else
			printf(" %d  <  %d < %d \n" , a ,  b , c);
	}



	return 0 ; 
}
