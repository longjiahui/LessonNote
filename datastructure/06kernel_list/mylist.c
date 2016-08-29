
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct {
	int id;
	char name[20];

	struct list_head list;
}student_t;

int main(void)
{
	LIST_HEAD(head);
	student_t *stu;

	while (1)
	{
		printf("input id name:");
		stu = malloc(sizeof(*stu));
		scanf("%d %s" , &stu->id, stu->name);
		
		if (stu->id < 0)
		{
			free(stu);
			break;
		}
	
		list_add(&stu->list, &head);
	}
	struct list_head *tmp;
/*

	for (tmp = head.next; tmp != &head; tmp = tmp->next)
	{
		stu = container_of(tmp, student_t, list);
		printf("id = %d, name = %s\n", stu->id, stu->name);

	}
*/
//#define list_for_each(pos, head) \
//	for (pos = (head)->next; pos != (head); pos = pos->next)

	list_for_each(tmp, &head)
	{
		stu = container_of(tmp, student_t, list);
		printf("id = %d, name = %s\n", stu->id, stu->name);
	}




	return 0;
}
