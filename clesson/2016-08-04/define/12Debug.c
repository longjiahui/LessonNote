
#include <stdio.h>
#include <stdlib.h>
#include <myhead.h>

int main(void)
{
	char *p = NULL ; 
	p = malloc(1024*1024);
	ERR(ENOMEM , NULL == p , 1 , goto e1 , "失败");
	
	char *q = NULL ; 
	q = malloc(1024*1024);
	ERR(ENOMEM , NULL == q , 1 , goto e2 , "失败");
	
	char *o = NULL ; 
	ERR(ENOMEM , NULL == o , 4 , goto e3 , "失败");


	return 0 ;

e3:
	free(q);
e2:
	free(p);
e1:
	return -ENOMEM ;
}

