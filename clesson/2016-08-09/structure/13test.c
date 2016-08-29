
#include <stdio.h>

struct student 
{
	int a ; 
	int b ; 
	int c ; 
};

//初始化1000结构体数组中的结构体变量

struct student Array[1000] = {
	[0 ... 998] = {
		.a = 100 ,
		.b = 200 ,
		.c = 300 ,
	},
};

int main(void)
{

	int i ; 
	for(i = 0 ; i < 1000 ; i++)
	{
	printf("i:%d a :%d b :%d c:%d  \n" , i , Array[i].a , Array[i].b , Array[i].c);
	}

	return 0 ; 
}

