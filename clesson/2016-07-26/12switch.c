
#include <stdio.h>

int main(void)
{

	int a ; 
	
	scanf("%d" , &a);

	float f = 33.33 ; 
	//只能传整型或者是字符型,不可以传浮点类型
	
	switch(f)
	{
		case  1: printf("this is 1 \n");  break;
		case  2: printf("this is 2 \n");  break;
		case  3: printf("this is 3 \n");  break;
		case  4: printf("this is 4 \n");  break;
		case  5: printf("this is 5 \n");  break;
		case  33.33: printf("this is 33.33 \n");  break;
		default : printf("this is unknown \n");  break;
	}


	return 0 ; 
}
