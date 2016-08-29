
#include <stdio.h>

int main(void)
{//一个函数的产生都要建栈   适用于C
	
	//int b ; //同一个代码块中,是不可以出现两个变量名相同的定义,或者声明

	int a = 100 ; 
	int b = 200 ; 
	char ch ='A'; 
	char pp = 'B'; 
	int c = 300;      //随机值
	int d = 400; 
	

	//变量申请 一般情况下从大到小,每一个相差4字节
	
	printf("a:%d  b:%d  c:%d  \n" , a , b , c );
	printf("&a:%p &b:%p &c:%p ch:%p d:%p pp:%p\n" , &a , &b , &c , &ch , &d , &pp);
	
	printf("a:%d b:%d\n" , a , *(int *)((char *)&a-4));


	return 0 ; 
}
