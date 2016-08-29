
#include <stdio.h>

int main(void)
{
	//++   前加  后加
	
	int i = 1 ; 
	int sum = 0 ; 

//	sum = ++i ; 
//	sum = i++ ; 
	
//	sum = i++ + i++ ; 
	sum = ++i + ++i ; 

	printf("sum: %d  i : %d  \n" , sum , i);

	return 0 ; 
}
