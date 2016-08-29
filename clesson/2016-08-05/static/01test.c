
#include <stdio.h>

//变量属于静态区,但是具有全局的特性
//当前变量只有在当前文件内有效
//进程生命周期  在程序初始化空间之时,分配空间并且初始化未初始化的区域(清零操作)

static int a = 100 ;   //初始化   非零才算初始化     extern
static int b ;         //未初始化
static int c = 0 ;     //未初始化


int main(void)
{
	

	printf("a:%d  b:%d  \n" , a  , b);


	return 0 ; 
}


