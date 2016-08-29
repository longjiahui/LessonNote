
#include <stdio.h>

//define返回值   是({  }) 中的最后一条语句的值就是define的返回值

#define   OPERATION         		\
		({							\
			int a ; 				\
			a = 100 ; 				\
			int b ; 				\
			b = 200 ; 				\
			int c ; 				\
			c = a + b ; 			\
			c;						\
		})
			

int  operation(void);

int main(void)
{
	int sum ; 

	sum = operation();

	printf("sum: %d \n" , sum);

	sum = OPERATION ;

	printf("sum: %d \n" , sum);
	
	return 0 ; 
}

int operation(void)
{
	int a ; 
	a = 100;
	int b ; 
	b = 200 ; 
	int c ;
	c = a + b ; 
	
	return c ; 
}

