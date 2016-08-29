
#include <stdio.h>

struct Student
{
	int Id ; 
	char Name[20] ;   //一般情况下,必须分配空间
	//char *name;  //段错误
	float  Score ; 
};

int Init_Struct(struct Student *Stu);

int main(void)
{

	//申请一个结构体变量,并且对它进行初始化
	struct Student Stu ; 
	
	Init_Struct(&Stu);

	printf("ID:%d  Name:%s  Score:%f \n" , Stu.Id , Stu.Name , Stu.Score);


	return 0 ; 
}

int Init_Struct(struct Student *Stu)
{
	printf("Pls input an Id: ");
	scanf("%d" , &Stu->Id);
	if(Stu->Id == -1)
		return -1 ; 

	printf("pls input a Name: ");
	scanf("%s" , Stu->Name);

	printf("pls input a Score: ");
	scanf("%f" , &Stu->Score);

	return 0 ; 
}
