
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct node {
	struct node *next, *prev;
}node_t;

void add_node(node_t *head, node_t *new);

/////////
typedef struct {
	int id;
	char name[20];

	node_t  list;
}student_t;

int main(void)
{
//	node_t head = {&head, &head};
	node_t head = LIST_HEAD_INIT(head);
	

	student_t *stu;
	while (1)
	{
		printf("input id name:");
		stu = malloc(sizeof(*stu));

		scanf("%d %s", &stu->id, stu->name);
		if (stu->id < 0)
		{
			free(stu);
			break;
		}

		add_node(&head, &stu->list);
	}
	//链表里的每个节点装的是结构体student_t对象成员list的地址
	
	node_t *tmp;
	for (tmp = head.next; tmp != &head; tmp = tmp->next)
	{
		//tmp 是student_t对象的list成员的地址

	//	stu = ((char *)tmp - offsetof(student_t, list));
		stu = container_of(tmp, student_t, list);
		printf("id = %d, name = %s\n", stu->id, stu->name);
	}
	



	return 0;
}

void add_node(node_t *head, node_t *new)
{
	new->next = head;
	new->prev = head->prev;
	
	head->prev->next = new;
	head->prev = new;
}
