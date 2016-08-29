
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	void *data;

	struct node *prev, *next;
}node_t;

#define QUEUE_LIST(name) \
	node_t name = {.prev = &name, .next = &name}

void enqueue(node_t *queue, void *data);
void *dequeue(node_t *queue);

typedef struct student {
	int id;
	char name[20];
}student_t;

int main(void)
{
	QUEUE_LIST(myqueue);
	student_t *p;

	while (1)
	{
		p = malloc(sizeof(*p));
		scanf("%d %s", &p->id, p->name);
		if (p->id < 0)
		{
			free(p);
			break;
		}

		enqueue(&myqueue, p);
	}	

	printf("dequeue: \n");
	while ((p = dequeue(&myqueue)) != NULL)
		printf("%d , %s\n", p->id, p->name);


	return 0;
}

void enqueue(node_t *queue, void *data)
{
	node_t *new;

	new = malloc(sizeof(node_t));
	new->data = data;
	
	new->next = queue;
	new->prev = queue->prev;

	queue->prev->next = new;
	queue->prev = new;
}

void *dequeue(node_t *queue)
{
	node_t *tmp = queue->next;
	void *data;

	if (tmp == queue)
		return NULL;
	
	//   a  -->  B ---> C
	tmp->next->prev = tmp->prev; // C->prev = a
	tmp->prev->next = tmp->next; // a->next = C

	data = tmp->data;
	free(tmp);
	return data;
}
