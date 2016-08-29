
#include <stdio.h>
//结构体与数组整合
//
#define  SIZE  5

struct Student
{
	int Id ; 
	char Name[20];
	float Score ; 
};

int Init_Struct(struct Student *Stu);
int Init_Struct(struct Student *Array);
void Print_Struct(struct Student *Array);

int main(void)
{
	//栈内地址
	//结构体数组
	
	struct Student Array[SIZE] = {0};
	Init_Struct(Array);

	Print_Struct(Array);

	return 0 ; 
}

int _Init_Struct(struct Student *Stu)
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

int Init_Struct(struct Student *Array)
{
	int i ; 
	for(i = 0 ; i < SIZE ; i++)
	{
		if(_Init_Struct(&Array[i]) == -1)
			return -1 ; 
	}
	return 0 ; 
}

void Print_Struct(struct Student *Array)
{
	int i ; 
	for(i = 0 ; i < SIZE ; i++)
	{
	printf("i:%d  Id:%d Name:%s Score:%f \n" , i , Array[i].Id , Array[i].Name , Array[i].Score);
	}
}

