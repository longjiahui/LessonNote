
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

int add_student(student_t *head)
{
	student_t *n;

	n = malloc(sizeof(student_t));
	printf("input id name: ");
	scanf("%d %s", &n->id, n->name);
	
	if (n->id < 0)
	{
		free(n);
		return -1;
	}

	n->next = head->next;
	head->next = n;

	return 0;
}

void show_students(const student_t *head)
{
	const student_t *n;

	for (n = head->next; n != NULL ; n = n->next)
		printf("id = %d, name = %s\n", n->id, n->name);
}

const student_t *find_student(const student_t *head, const int id)
{
	const student_t *n;
	
	for (n = head->next; n != NULL; n = n->next)
	{
		if (n->id == id)
			return n;
	}
	return NULL;
}

int main(void)
{
	student_t  head = {.next = NULL}; //职业头节点
	const student_t  *n;	

	while (add_student(&head) == 0)
		;

	show_students(&head);

	n = find_student(&head, 22);
	if (n)
		printf("found : id=%d, name=%s\n", n->id, n->name);
	


	//回收节点
	student_t *tmp;
	for (n = head.next; n != NULL; )
	{
		tmp = n->next;
		free((student_t *)n);
		n = tmp;
	}

	return 0;
}
