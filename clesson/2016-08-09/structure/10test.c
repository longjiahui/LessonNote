

#include <stdio.h>
//结构体  位段

struct Student
{
	char ca:1 ; 
	char cb:1 ;
	char cc:2 ;
	char cd:4 ; 
	char ce:1 ; 
	char cf:1 ; 
	char cg:1 ; 
	char ch:1 ; 
	char ci:1 ; 
	char cj:1 ; 
	char ck:1 ; 
	short b ; 
	//char kk:0 ;  
};


int main(void)
{
	int array[0] ; 
	printf("sizearray:%d \n" , sizeof(array));
	printf("size:%d \n" , sizeof(struct Student));
	printf("size:%d \n" , sizeof(struct { int:0;}));
	return 0 ;
}
