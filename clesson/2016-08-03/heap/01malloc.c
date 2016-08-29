
//堆
#include <stdio.h>
#include <stdlib.h>  //标准库头文件
//申请一个堆的空间
//malloc   ==>  allocate  分配空间    分配堆空间  不连续
//calloc
//realloc  ==>  连续分配堆空间,也就是说在原来的基础上再分配空间 扩充 
//typedef   unsigned int  uint32 ; 
//typedef   uint32     size_t    ;
//		 //             成员数量      每个成员大小
//       void *calloc(size_t nmemb, size_t size);
//       //分配一块空间   块空间大小
//       void *malloc(size_t size);
//       //释放堆空间
//       void free(void *ptr);
//       //连续申请空间大小  所指的堆地址   加长大小
//       void *realloc(void *ptr, size_t size);
//


int main(void)
{
	//free时不可以free栈空间地址   要不然会报栈错误
	//int a = 200 ; 
	//free(&a);

	//如果想申请大数组,最好在堆内申请
	char *p = NULL ;
	//堆空间
	p = malloc(20);
	if(NULL == p)
	{
		perror("malloc fail");
		return -1 ; 
	}

	#if 0
	p = calloc(20,1);
	if(NULL == p)
	{
		perror("calloc fail");
		return -1 ; 
	}
	#endif
	
	int i ;
	for(i = 0 ; i < 19 ; i++)
	{
		p[i] = 'A';
	}
	p[19]='\0';

	printf("p:%s \n" , p);

	//释放空间
	free(p);	
	free(NULL);  //no operation is performed  //no used

	return 0 ;
}



