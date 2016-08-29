
#include <stdio.h>

int function(int num);

int main(void)
{

	int i ; 
	for(i = 0 ; i < 45 ; i++)
	{
		printf("value:%d  \n" , function(i));
	}



	return 0 ; 
}
int function(int num)
{
	if((num == 0) || (num == 1))
		return  1 ; 
	return  function(num-1)+function(num-2);
}
