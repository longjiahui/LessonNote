
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char *p = NULL ; 
#if 0
	//malloc分配空间是不连续
	p = malloc(1);      //导致内存泄漏
	if(NULL == p)
	{
		perror("malloc fail");  //默认会换行
		return -1 ; 
	}

	printf("p:%p \n" , p);

	p = malloc(1);
	if(NULL == p)
	{
		perror("malloc fail");  //默认会换行
		return -1 ; 
	}
	
	printf("p:%p \n" , p);

	free(p);
#endif
#if 1
	//malloc分配空间是不连续
	p = malloc(1024*1024);      //不会导致内存泄漏
	if(NULL == p)
	{
		perror("malloc fail");  //默认会换行
		return -1 ; 
	}

	printf("p:%p \n" , p);

	p = realloc(p , 2048*1024);
	if(NULL == p)
	{
		perror("malloc fail");  //默认会换行
		return -1 ; 
	}
	
	printf("p:%p \n" , p);

	free(p);
#endif

	return 0 ;
}
