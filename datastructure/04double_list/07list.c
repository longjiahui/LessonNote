
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
	node_t *n;
	int num;

	while (1)
	{
		printf("input number: ");
		scanf("%d", &num);

		if (num < 0)
			break;
		
		n = malloc(sizeof(node_t));
		n->data = num;

		n->next = &head;
		n->prev = head.prev;

		head.prev->next = n; //这里是head.prev表示头节点的前一个节点(也就是尾节点)的next指针变量
		head.prev = n; //头节点的prev指针变量存放n节点地址
	}

	for (n = head.prev; n != &head; n = n->prev)
		printf("%d\n", n->data);


	printf("input number to delete:");
	scanf("%d", &num);

	for (n = head.prev; n != &head; n = n->prev)
	{
		if (n->data == num)
		{	
			n->prev->next = n->next;
			n->next->prev = n->prev;
			free(n);
			break;
		}
	}
	
	printf("after delete:\n");
	for (n = head.prev; n != &head; n = n->prev)
		printf("%d\n", n->data);
		


	return 0;
}

