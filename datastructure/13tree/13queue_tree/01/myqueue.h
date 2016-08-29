
#ifndef __MYQUEUE_H

#define __MYQUEUE_H

typedef struct node {
	void *data;

	struct node *prev, *next;
}node_t;

#define QUEUE_LIST(name) \
	node_t name = {.prev = &name, .next = &name}

void enqueue(node_t *queue, void *data);
void *dequeue(node_t *queue);

#endif /* __MYQUEUE_H */
