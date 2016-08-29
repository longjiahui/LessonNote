
#include <stdio.h>
#include <string.h>

struct Student 
{
	int ID ;
};

int main(void)
{
	
	char Buffer[10] = {0};
	char Tmp[20] = {0};
	struct Student Stu ; 
	//清结构体
	memset(&Stu , 0 , sizeof(struct Student));
	//清内存
	memset(Buffer , 'A' , 9);

	printf("Buffer:%s \n" , Buffer);
	//内存复制 
	memcpy(Tmp , Buffer , 10);  //strcpy

	printf("Tmp:%s \n" , Tmp);
	//内存移动


	return 0 ; 
}
