
#include <stdio.h>


int main(void)
{
	//int a  ;  //==>  auto  signed int a ; 
	//64大概率为0   栈内变量
	//32大概率为随机值
	//printf("a : %d \n" , a);

#if 0
	unsigned int  ui ; 
	//int i ; 
	
	//max
	ui = 0xFFFFFFFF ; 
	printf("max: %u \n" , ui);

	//middle
	ui = 0x7FFFFFFF ; 
	printf("mid:%u \n" , ui);

	//min
	ui = 0 ; 
	printf("min:%u \n" , ui);
#endif
	//signed 高位为符号位
	// 0    正数
	// 1    负数
	
	int  ui ; 
	//计算机内如何记录负数
	//补码  ==>  反码＋1
	
	//max
	ui = 0xFFFFFFFF ; 
	printf("max: %d \n" , ui);

	//middle  正数最大值
	ui = 0x7FFFFFFF ; 
	printf("mid:%d \n" , ui);

	//middle + 1
	ui = 0x7FFFFFFF + 1;   //0x80000000    负的最小值
	printf("mid+1:%d \n" , ui);

	//min
	ui = 0 ; 
	printf("min:%d \n" , ui);


	return 0 ; 
}
