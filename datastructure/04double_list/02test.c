
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	int data;

	struct node *next;
	struct node *prev;
}node_t;

void func(node_t **dd);
int main(void)
{
	node_t *head = NULL; //要求在其它函数里初始化它	
	func(&head); // func(NULL);	
	
	

	return 0;
}

void func(node_t **dd)
{
	printf("%p\n", &dd);
	
//	dd == &head
//	dd = malloc(sizeof(node_t)); //只是修改二级指针变量dd存放的地址
//	(*dd) == head	

	*dd = malloc(sizeof(node_t));	
}
