
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
	int i ; 
	if((num == 0) || (num == 1))
		return 1 ; 
	int front = 1 ; 
	int back  = 1 ; 
	for(i = 1 ; i < num ; i++)
	{
		front = back + front; 
		back = front - back ; 
	}
	return front ; 
}
