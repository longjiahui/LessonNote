
#include <stdio.h>

//##  字符串粘贴符

#define  ERR1	printf("找不到该文件\n");
#define  ERR2	printf("网络连接失败\n");
#define  ERR3	printf("打开文件失败\n");
#define  ERR4	printf("内存溢出\n");
#define  ERR5	printf("我也不知道\n");

#define  ERR(x)					\
	do							\
	{							\
		ERR##x					\
	}while(0);


int main(void)
{

	ERR(1)
	ERR(4)
	ERR(5)

	return 0 ; 
}
