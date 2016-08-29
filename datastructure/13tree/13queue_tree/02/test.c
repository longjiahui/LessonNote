
#include <stdio.h>
#include <stdlib.h>
#include "myqueue.h"

struct node {
	int data;
	
	struct node *left;
	struct node *right;
};
void print_tree(struct node *head, int level, int type);
void add_node(struct node **head, struct node *new);

int main(void)
{
	struct node *head = NULL;
	struct node *tmp, *new;
	QUEUE_LIST(myqueue);

	while (1)
	{
		new = malloc(sizeof(*new));
		printf("input num: ");
		scanf("%d", &new->data);
		new->left = NULL;
		new->right = NULL;
	
		if (new->data < 0)
			break;
		
		add_node(&head, new);
		print_tree(head, 0, 0);
	}

	enqueue(&myqueue, head);
	while (NULL != (tmp = dequeue(&myqueue)))
	{
		printf("%d ", tmp->data);
		if (NULL != tmp->left)
			enqueue(&myqueue, tmp->left);
		if (NULL != tmp->right)
			enqueue(&myqueue, tmp->right);
	}
}

void add_node(struct node **head, struct node *new)
{
	struct node *tmp;

		if (NULL == *head)
		{
			*head = new;
			return;
		}
		//////////////////
		tmp = *head;
		while (tmp)
		{
			while ((new->data >= tmp->data) && (tmp->right != NULL))
				tmp = tmp->right;
			
			if ((NULL == tmp->right) && (new->data >= tmp->data))
				break;
			
			while ((new->data < tmp->data) && (tmp->left != NULL))
				tmp = tmp->left;
	
			if ((NULL == tmp->left) && (new->data < tmp->data))
				break;
		}
		if (new->data < tmp->data)
			tmp->left = new;
		else
			tmp->right = new;
}

void print_tree(struct node *head, int level, int type)
{
	int i;

	if (NULL == head)
		return;
	print_tree(head->right, level+1, 2);	

	if (0 == type)
		printf("%02d\n", head->data);
	if (1 == type) //左节点
	{
		for (i = 0; i < level; i++)
			printf("\t");
		printf("\\\n");
		
		for (i = 0; i < level; i++)
			printf("\t");
		printf("  %02d\n", head->data);
	}
	if (2 == type)
	{
		for (i = 0; i < level; i++)
			printf("\t");
		printf("  %02d\n", head->data);
		for (i = 0; i < level; i++)
			printf("\t");
		printf("/\n");
	}	

	print_tree(head->left, level+1, 1);
}

