
#include <stdio.h>
#include <stdlib.h>
#include "myqueue.h"

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
