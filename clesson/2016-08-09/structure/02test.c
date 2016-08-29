
#include <stdio.h>
#include <string.h>

struct Student
{
	int Id ; 
	float Score ; 
	int Sex ; 
};

struct student
{
	int Id ; 
	float Score ; 
	int Sex ; 
};


int main(void)
{
	struct Student Stu = {12,33.33,1}; 
	struct Student Suu ; 
	struct student Stt ; 

	
	//结构体的赋值
	//Suu = Stu ;   //相同类型的结构体之间可以整体赋值
	
	//Stt = (struct student)Stu ;   //不可以强转结构体类型,只能强转结构体指针类型
	//不同结构体类型,但是结构体结构一样,不可以直接赋值
	
//	Stt = Stu ; 
	//如果结构类型一致,但是结构体的类型不一致,就用memcpy来赋值
	memcpy(&Stt , &Stu , sizeof(struct Student));

	printf("ID:%d Score:%f Sex:%d \n" , Stu.Id , Stu.Score , Stu.Sex);
	printf("ID:%d Score:%f Sex:%d \n" , Stt.Id , Stt.Score , Stt.Sex);



	return 0 ; 
}
