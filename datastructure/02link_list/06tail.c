
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
	struct mylist_t *node, 
			*tail = NULL; //专门记录链表的尾节点地址
	int num;

	while (1)
	{
		printf("input num: ");
		scanf("%d", &num);
		
		if (num < 0)
			break;

		node = malloc(sizeof(*node));
		node->data = num;
		node->next = NULL;
	
		if (NULL == head.next) //链表里没有节点时的处理
			head.next = node;
		else     //已有节点的处理, 从尾节点加入
			tail->next = node;
		tail = node; //新创建出来的节点成为尾节点	
	}

	struct mylist_t *tmp;
	for (node = head.next; node != NULL; tmp=node->next, free(node), node=tmp)
	{
		printf("%d\n", node->data);
//		tmp = node->next;
//		free(node);
//		node = tmp;
	}
	return 0;
}
