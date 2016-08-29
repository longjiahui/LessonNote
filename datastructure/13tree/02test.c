
#include <stdio.h>

struct node {
	int data;
	
	struct node *left;
	struct node *right;
};
void show_tree(struct node *head, int type); // type 0前序，1中序，2后序
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
	
	printf("\n前序:");
	show_tree(head, 0);


	printf("\n中序:");
	show_tree(head, 1);

	
	printf("\n后序:");
	show_tree(head, 2);


	return 0;
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
