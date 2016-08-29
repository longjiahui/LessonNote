
#include <stdio.h>

struct Student
{
	int Id ; 
	int Sex ; 
};

struct student
{
	int Id ; 
	int Sex ; 
};

int main(void)
{
	struct Student  Stu = {19,290}; 
	struct student *p = NULL ;

	//结构体下想做类型转换只能通过结构体指针
	p = (struct student *)&Stu ; 

	printf("id:%d  sex:%d  \n" ,  p->Id , p->Sex);

	return 0 ; 
}
