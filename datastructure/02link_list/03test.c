
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mylist_t {
	char line[1024];
	struct mylist_t *next;
};

//用链表来记录用户输入的字符串

int main(void)
{
	struct mylist_t *head = NULL, *new = NULL;

	while (1)
	{
		new = malloc(sizeof(struct mylist_t));
		printf("input string:");
		scanf("%s", new->line);
	
		if (strcmp("exit", new->line) == 0)
		{
			free(new);
			break;	
		}
		
		new->next = head;
		head = new;
	}	

	struct mylist_t *tmp;

	for (new = head; new != NULL; )
	{
		printf("%s\n", new->line);
		tmp = new->next;
		free(new);
		new = tmp;
	}
	return 0;
}
