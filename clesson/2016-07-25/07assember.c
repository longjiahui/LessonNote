
#include <stdio.h>

int main(void)
{
	int a = 2; 

	int b = 10 ;	
	
	int c ; 
	c = a + b ; 
	c = a - b ; 
	c = a * b ; 
	c = a / b ;   //直接取整 去掉小数点
	c = a % b ; 
	//小数点 必须用float  double

	printf("sum:%d \n" , 99/2);
	
	float e = 49 ; 
	float d = 2 ; 
	float sum ; 

	sum = e / d ;   //float默认情况下小数点后面保留6位
	printf("sum:%f  \n" , sum);


	int f = 10 ; 
//	f = f + 2 ; 
	f += 2 ;   //  += /=  -=  *=  %=  >>=  <<= &=  |=  ~=

	printf("f: %d \n" , f);

	return 0 ; 
}
