
#include <stdio.h>
//结构体的对齐方式

struct Student
{
	char *p ;   
	char Buffer[13];   
	int  i ;   
};//24   32


int main(void)
{
	printf("size:%d \n" , sizeof(struct Student));
	

	return 0 ; 
}

