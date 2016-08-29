
#include <stdio.h>

int main(void)
{
	//刷缓冲区的条件
	//1.如果碰到\n   
	//2.缓冲区满
	//3.程序退出时,回收资源刷

	//向下单行执行
	//
	//1. \n 换行
	//2. 刷标准输出缓冲区
	
	printf("hello world");
	printf("hello world");
	
	//刷缓冲区
	//printf("\n");
	//0        1       2
	//stdin   stdout   stderr
	fflush(stdout);
	//fflush(NULL);  //刷所有的标准缓冲区

	//睡眠5s
	sleep(5);


	return 0 ; 
}

