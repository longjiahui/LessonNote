
#include <stdio.h>

//联合体  也叫共用体
//共同拥有相同的物理空间,但是同一时刻只能使用一个
//决定大小由最大的类型决定

union  Student 
{
	int a ; 
	int b ; 
	int c ; 
	double f ; 
	long  p ; 
};


int main(void)
{
	union Student  Stu ; 
	Stu.a = 100 ; 
	Stu.c = Stu.a + Stu.b ; 
	Stu.f = 33.33 ; 

	printf("Stu.a:%d Stu.b:%d  \n" , Stu.a , Stu.b);
	printf("Stu.b:%d \n" , Stu.b);

	printf("size:%d \n" ,  sizeof(union Student));

	return 0 ; 
}

