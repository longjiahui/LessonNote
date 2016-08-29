
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//单链表倒置方法：遍历链表时，作头部插入节点即可
// A   -->  B  --> C   --> D --> NULL
//
// 倒置： A --> NULL
// 倒置： B --> A --> NULL
// 倒置： C --> B --> A --> NULL
// 倒置： D --> C --> B --> A --> NULL

typedef struct node {
	int data;

	struct node *next;
}node_t;

int main(void)
{
	node_t  head = {.next = NULL};
	node_t *n;
	int    num;

	while (1)
	{
		printf("input number: ");
		scanf("%d", &num);
		if (num < 0)
			break;

		n = malloc(sizeof(node_t));
		n->data = num;

		n->next = head.next;
		head.next = n;	
	}
	
	for (n = head.next; n != NULL; n = n->next)
		printf("%d ", n->data);
	printf("\n\n");
/////////////////////////	 
// 链表倒置

	node_t  head2 = {.next = NULL}; //另一个链表头节点
	node_t *tmp;

	for (n = head.next; n != NULL; )
	{
		tmp = n->next;

		n->next = head2.next;
		head2.next = n;

		n = tmp;
	}	
	
	for (n = head2.next; n != NULL; n = n->next)
	{
		printf("%d ", n->data);
	}
	printf("\n\n");



	return 0;
}
