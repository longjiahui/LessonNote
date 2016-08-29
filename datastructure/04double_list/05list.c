
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
	node_t head = {.data = 0, .next = &head, .prev = &head};

///////////
	node_t a;

	a.data = 1122;
	a.next = &head;
	a.prev = head.prev;

	head.prev->next = &a;
	head.prev = &a;	

//////////
	node_t b;

	b.data = 7788;
	b.next = &head;
	b.prev = head.prev;

	head.prev->next = &b;
	head.prev = &b;
///

	node_t *tmp = &head;

	for (; tmp != NULL; tmp = tmp->next)
	{
		printf("%d\n",  tmp->data);
		sleep(1);
	}

	return 0;
}

