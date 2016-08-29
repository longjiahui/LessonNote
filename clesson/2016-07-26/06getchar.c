
#include <stdio.h>

int main(void)
{
	
	int number ; 
	
	char ch ; 

	scanf("%d" , &number );
	
	//吃掉scanf最后的\n
	ch = getchar();


	ch = getchar();
	putchar(ch);

	printf("number:%d \n" , number);



	return 0 ;
}
