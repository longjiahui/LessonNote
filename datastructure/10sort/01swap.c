
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 55, b = 66;

	//不经过第三个变量来实现a, b 交换变量值
/*	
	a = (a+b); 
	b = a-b;
	a = a-b; 	
*/
	a = b ^ a; // 一个数异或一个数两次可以恢复
	b = b ^ a;
	a = a ^ b;	

	printf("a = %d, b = %d\n", a, b);
	return 0;
}
