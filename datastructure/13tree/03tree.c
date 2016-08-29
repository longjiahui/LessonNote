
#include <stdio.h>

struct node {
	int data;
	
	struct node *left;
	struct node *right;
};
void show_tree(struct node *head, int type); // type 0前序，1中序，2后序
void print_tree(struct node *head, int level, int type);
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

		if (NULL == head)
		{
			head = new;
			continue;
		}
		//////////////////
		tmp = head;
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

	print_tree(head, 0, 0);

	return 0;
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

void show_tree(struct node *head, int type)
{
	if (NULL == head)
		return;
	if (0 == type)
		printf("%02d ", head->data);

	show_tree(head->left, type);

	if (1 == type)
		printf("%02d ", head->data);

	show_tree(head->right, type);
	
	if (2 == type)
		printf("%02d ", head->data);

}
