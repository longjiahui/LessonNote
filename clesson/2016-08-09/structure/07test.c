
#include <stdio.h>
#include <stdlib.h>

//结构体与数组整合
//
#define  SIZE  5

struct Student
{
	int Id ; 
	char Name[20];
	float Score ; 
};

int _Init_Struct(struct Student *Stu);
int Init_Struct(struct Student *Array[SIZE]);
void Print_Struct(struct Student *Array[SIZE]);

int main(void)
{
	//栈内地址
	//结构体指针数组
	struct Student *Array[SIZE] = {0};
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

int Init_Struct(struct Student *Array[SIZE])
{
	int i ; 

	for(i = 0 ; i < SIZE ; i++)
	{
		Array[i] = malloc(sizeof(struct Student));
		if(NULL == Array[i])
		{
			perror("Malloc fail");
			goto Err ; 
		}

		if(_Init_Struct(Array[i]) == -1)
		{
			goto Err ; 
		}
	}
	return 0 ; 

Err:
	while(--i)
	{
		free(Array[i]);
	}

	return -2 ; 
}

void Print_Struct(struct Student *Array[SIZE])
{
	int i ; 
	for(i = 0 ; i < SIZE ; i++)
	{
	printf("i:%d  Id:%d Name:%s Score:%f \n" , i , Array[i]->Id , Array[i]->Name , Array[i]->Score);
	}
}

