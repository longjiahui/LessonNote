
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1024

struct mylist_t {
	int data;
	struct mylist_t *next;
};

//用链表来记录用户输入的字符串

int main(void)
{
	struct mylist_t head = {0, NULL}; //专门做头节点，不参与存放数据
	struct mylist_t *node;
	int num;

	while (1)
	{
		printf("input num: ");
		scanf("%d", &num);
		
		if (num < 0)
			break;

		node = malloc(sizeof(*node));
		node->data = num;
		
		node->next = head.next;
		head.next = node;    //新加入节点在头节点的next指针指向		
	}

	struct mylist_t *tmp;
	for (node = head.next; node != NULL; )
	{
		printf("%d\n", node->data);
		tmp = node->next;
		free(node);
		node = tmp;
	}
	return 0;
}
