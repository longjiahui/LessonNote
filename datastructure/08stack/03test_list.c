
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *next, *prev;
}stack_t;


typedef struct {
	int id;
	char name[20];

	struct node  list;
}student_t;

void push_stack(stack_t *head, student_t *stu);
int pop_stack(stack_t *head,   student_t *stu);

static stack_t head = {&head, &head}; //栈的链表头
int main(void)
{
	student_t stu;

	while (1)
	{
		printf("input id name:");
		scanf("%d %s", &stu.id, stu.name);
		if (stu.id < 0)
			break;

		push_stack(&head, &stu);
	}
	
	while (0 == pop_stack(&head, &stu))
	{
		printf("id = %d, name = %s\n", stu.id, stu.name);
	}
	
	return 0;
}

int pop_stack(stack_t *head, student_t *student)
{
	struct node *tmp = head->next;
	student_t *stu;

	if (tmp == head) //空栈
		return -1;

	//让这个节点退出栈链表
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;

	stu = (student_t *)((char *)tmp - (char *)(&((student_t *)0)->list));
	*student = *stu;

	free(stu);
	return 0;
}

void push_stack(stack_t *head, student_t *student)
{
	student_t *stu = malloc(sizeof(student_t));
	struct node *new;
	
	*stu = *student;
	new = &stu->list;

	new->next = head->next;
	new->prev = head;
	
	head->next->prev = new;
	head->next = new;
}
