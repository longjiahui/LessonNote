
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	int id;
	char name[20];
	float score;
	char tel[20];

	struct student *next;
}student_t;

int main(void)
{
	student_t  head = {.next = NULL}; //职业头节点
	student_t  *n;	

	while (1)
	{	
		n = malloc(sizeof(student_t));
		printf("input id name: ");
		scanf("%d %s", &n->id, n->name);
	
		if (n->id < 0)
		{
			free(n);
			break;
		}
		
		n->next = head.next;
		head.next = n;
	}	

	student_t *tmp;
	for (n = head.next; n != NULL; )
	{
		printf("id = %d, name = %s\n", n->id, n->name);
		tmp = n->next;
		free(n);
		n = tmp;
	}

	return 0;
}
