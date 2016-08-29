
#include <stdio.h>
#include <stdlib.h>  //malloc包含 标准库文件

//goto层次退出
int main(void)
{
	char *p = NULL ; 

	p = malloc(1024*1024);  //1M
	if(NULL == p)
	{
		goto OUT ;
	}

	char *q = NULL ; 
	q = malloc(1024*1024);
	if(NULL == q)
	{
		goto OUT1 ; 
	}
	char *i = NULL ; 
	i = malloc(1024*1024);
	if(NULL == i)
	{
		goto OUT2 ;
	}

	char *j = NULL ; 
	j = malloc(1024*1024);
	if(NULL == j)
	{
		goto OUT3 ; 
	}


	return 0 ; 

OUT3:
	free(i);
OUT2:
	free(q);
OUT1:
	free(p);
OUT:
		printf("malloc fail");
	return -1 ; 
}
