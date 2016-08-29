
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	void *data;

	struct node *prev;
	struct node *next;
}node_t;

void add_node(node_t *head, void *data);

typedef struct {
	int id;
	char name[20];
	
}student_t;

int main(void)
{
	node_t head = {NULL, &head, &head};
	student_t *stu;

	while (1)
	{
		stu = malloc(sizeof(*stu));
		printf("input id name:");
		scanf("%d %s", &stu->id, stu->name);
	
		if (stu->id < 0)	
		{
			free(stu);
			break;
		}

		add_node(&head, stu);
	}
	////////
	node_t *n;

	for (n = head.next; n != &head; n = n->next)
	{
		stu = (student_t *)n->data;
		printf("%d, %s\n", stu->id, stu->name);
	}	

	return 0;
}

void add_node(node_t *head, void *data)
{
	node_t *n;

	n = malloc(sizeof(node_t));
		
	n->data = data;
	
	n->next = head;
	n->prev = head->prev;
	
	head->prev->next = n;
	head->prev = n;
}

