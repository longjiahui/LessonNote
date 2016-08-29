
#include <stdio.h>

int main(void)
{
	//stdin     stdout   stderr
	//标准输入 标准输出 标准出错
	

	//fprintf(stdout , "hello world \n");
	//fprintf(stderr, "hello world \n");
	//printf("hello world \n");
	
	int  num ; 
	
	fprintf(stdin , "%d" , 123); //用处不大
	scanf("%d" , &num);

	printf("num:%d \n" , num);

	return 0 ; 
}

