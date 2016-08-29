
#include <stdio.h>

struct Student 
{
	int a ; 
	int b ; 
};

struct Class
{
	struct Student stu1 ; 
	struct Student stu2 ; 
}tt={{100,200},{300,400}};

struct Class  class1 = {
	.stu1 = {
		.a = 100 , 
		.b = 200 , 
	},
	.stu2 = {
		.a = 300 ,
		.b = 400 ,
	},
};

int main(void)
{
	struct Class class2 = {{200,300},{400,500}};

	printf("a : %d b: %d a:%d b:%d \n" , class1.stu1.a , class1.stu1.b , class1.stu2.a , class1.stu2.b);
	printf("a : %d b: %d a:%d b:%d \n" , class2.stu1.a , class2.stu1.b , class2.stu2.a , class2.stu2.b);


	return 0 ; 
}
