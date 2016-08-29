
#include <stdio.h>


//结构体的类型定义
typedef  struct   //XXXX
{//如果有类型定义的话,结构体的名字可写,可不写
	int a ; 
	int b ; 
}Student_t;



int main(void)
{
	Student_t  aa = {199,200}; 

	printf("a:%d b:%d  \n" , aa.a , aa.b);

	return 0 ; 
}
