
#include <stdio.h>

//int ppp ;  //非正规写法  //相当于声明
extern int ppp ;   //正规  //外部变量

int main(void)
{
	//调用了外部函数
	
	function();

	printf("ppp:%d  \n" , ppp);
	
	return 0 ; 
}
