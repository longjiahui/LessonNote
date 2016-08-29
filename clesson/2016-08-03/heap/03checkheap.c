
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	char *p = NULL ;
	
	int count = 0 ; 
	//64位下堆的大小接近无穷  4G*4G
	//32位下堆的大小  3G
	
	while(1)
	{
		p = malloc(1024*1024);
		if(NULL == p)
		{
			perror("malloc fail");
			break;
		}
		count++ ;
		printf("count:%d \n" , count);
	}


	return 0 ; 
}

