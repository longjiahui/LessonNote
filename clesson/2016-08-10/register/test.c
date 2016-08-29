
#include <stdio.h>

int main(void)
{
	//寄存器变量
	//当整型用
	register  aa ; 

	register  cpsr ; 
	cpsr = 100 ; 

	printf("sizeof:%d \n" , sizeof(aa));
	printf("cpsr:%d \n" , cpsr);


	return 0 ; 
}
