
#ifndef __MYQUEUE_H

#define __MYQUEUE_H

typedef struct queue {
	const void *data;

	struct queue *prev, *next;
}queue_t;

#define QUEUE_LIST(name) \
	queue_t name = {.prev = &name, .next = &name}

void enqueue(queue_t *queue, const void *data);
void *dequeue(queue_t *queue);

#endif /* __MYQUEUE_H */
