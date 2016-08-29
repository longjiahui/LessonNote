
#include <stdio.h>

int main(void)
{
	int i ; 
	for(i = 0 ;  ; i++)
	{
		if((i%2==1) && (i%3==2) && (i%5==4) && (i%6==5) && (i%7 == 0)&&(i%11==3))
		{
			printf("i:%d \n" , i);
			break;
		}
	}


	return 0 ; 
}
