
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	int data;

	struct node *next;
	struct node *prev;
}node_t;


int main(void)
{
	node_t head = {.next = NULL, .prev = NULL};
	node_t *n;
	int num;

	//头部插入
	
/*
 *
	C --> B --> A  --> NULL
  NULL  <--A  <-- B <-- C
 *
 */
	
	while (1)
	{
		printf("input number: ");
		scanf("%d", &num);

		if (num < 0)
			break;

		n = malloc(sizeof(node_t));
		n->data = num;

		n->next = head.next;
		n->prev = head.prev;

		head.next = n;
		head.prev = n;
	}
		
	for (n = head.next; n != NULL; n = n->next)
		printf("%d ", n->data);
	printf("\n\n");

	for (n = head.prev; n != NULL; n = n->prev)
		printf("%d ", n->data);
	printf("\n\n");
	
	

	return 0;
}
