
#include <stdio.h>

//#define  DEBUG
//#define  RELEASE



int main(void)
{
	int a ; 
	int b ; 
	a = 100 ; 
	b = 200 ; 

	int c ; 
	c = a + b ; 
#ifdef  DEBUG
	printf("hello c:%d a:%d b:%d \n" , c , a , b);
#endif
#ifdef  RELEASE
	printf("%3d + %3d = %3d \n" , a , b , c);
#endif

	return 0 ; 
}
