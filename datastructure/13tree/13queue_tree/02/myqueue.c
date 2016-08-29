
#include <stdio.h>
#include <stdlib.h>
#include "myqueue.h"

void enqueue(queue_t *queue, const void *data)
{
	queue_t *new;

	new = malloc(sizeof(queue_t));
	new->data = data;
	
	new->next = queue;
	new->prev = queue->prev;

	queue->prev->next = new;
	queue->prev = new;
}

void *dequeue(queue_t *queue)
{
	queue_t *tmp = queue->next;
	const void *data;

	if (tmp == queue)
		return NULL;
	
	//   a  -->  B ---> C
	tmp->next->prev = tmp->prev; // C->prev = a
	tmp->prev->next = tmp->next; // a->next = C

	data = tmp->data;
	free(tmp);
	return (void *)data;
}
