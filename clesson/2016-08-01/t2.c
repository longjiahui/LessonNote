
#include <stdio.h>

#define  NR(x)   (sizeof(x)/sizeof(x[0]))

int main(void)
{
	int array[10] = {10,10,10,9,9,9,10,10,10,10};

	int i ; 
	int max = array[0]; 
	int second = array[0]; 

	for(i = 0 ; i < NR(array) ; i++)
	{
		if((array[i] > max) && ( max > second))
		{
			second = max ; 
			max = array[i];
		}else if((max == second) &&  (array[i] < max))
		{
			second = array[i] ; 
		}else if((second < array[i]) && (array[i] < max))
		{
			second = array[i] ; 
		}
	}

	if(max == second)
		printf("找不到第二大的元素\n");
	else
		printf("max:%d second:%d \n" , max , second);



	return 0 ; 
}
