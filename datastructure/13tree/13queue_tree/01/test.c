
#include <stdio.h>
#include <stdlib.h>
#include "myqueue.h"


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

