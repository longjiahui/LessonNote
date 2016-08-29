

#include <stdio.h>
//结构体  位段

struct Student
{
	int a ; 
	int b ; 
	int *p ;
	//int array[0] ;   //引领一个指针,指向一块数据
};

struct student
{
	int a ; 
	int b ; 
	int bb[100] ; 
};



int main(void)
{
	struct Student stu ; 

	printf("size:%d \n" , sizeof(stu));
	printf("size:%d \n" , sizeof(struct Student));
	return 0 ;
}

