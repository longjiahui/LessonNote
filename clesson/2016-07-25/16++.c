
#include <stdio.h>

int main(void)
{
	int i = 0 ;

	printf("%d  %d  \n" , i++ , i++);
	// 0  0
	// 0  1
	// 1  0
	// 1  1
	

	printf("%d  %d  \n" , ++i , ++i);
	// 4  4
	// 3  4
	// 4  3
	
	//9  9

	return 0 ; 
}
