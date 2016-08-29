
#include <stdio.h>
//结构体的对齐方式

struct Student
{
	int a ;
	int b ; 
	char ch ; 
	short sh ; 
	char pp ; 
};

//类型最大的决定结构体的对齐方式
//排列应该从小到大,相同类型放一起

//规定结构体的对齐方式
#pragma   pack(1)  //规定结构体的对齐方式
struct student
{
	long i ; 
	char pp ; 
	int  ii ; 
	char ch ; 
};
#pragma   pack()  //取消结构体的对齐方式


int main(void)
{
	printf("size:%d \n" , sizeof(struct student));
	

	return 0 ; 
}

