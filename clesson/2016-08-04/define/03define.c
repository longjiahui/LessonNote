
#include <stdio.h>

//'\'  要求 必须是当前行的最后一个字符
//将下一行并入define,所以最后一行不写'\'

#define  DEBUG  				 \
	printf("hello world  \n");   \
	printf("hello kitty  \n");   
//1.作用域不受外界影响
//2.异常抓取

#define  AAA				\
	do						\
	{						\
		int a = 200 ;		\
		printf("hello \n"); \
	}while(0);				

int main(void)
{
	int a ; 

	DEBUG
	DEBUG
	AAA;

	return 0 ; 
}
