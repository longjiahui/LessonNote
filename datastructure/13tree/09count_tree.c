
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	
	struct node *left;
	struct node *right;
};
void print_tree(struct node *head, int level, int type);
void add_node(struct node **head, struct node *new);

int count_node(struct node *head);
int main(void)
{
	struct node *head = NULL;
	struct node *tmp, *new;

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

	printf("%d\n", count_node(head));

}

int count_node(struct node *head)
{
	int lc, rc;

	if (NULL == head)
		return 0;
	
	lc = count_node(head->left);
	rc = count_node(head->right);
	return lc+rc+1;
}
/*
	55
      /    \
     44    66

1. count_node(55)
     lc = count_node(44); // lc = 1
      ...
     rc = count_node(66); // rc = 1
     return lc+rc+1;

	2. count_node(44)
		lc = 0;
		rc = 0;
		return 1;

		3. count_node(66)
			lc = 0;
			rc = 0
			return 1;

*/

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
