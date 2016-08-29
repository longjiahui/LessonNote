
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

void turn_right(struct node **head); //原根节点的左节点成为新根节点，原根节点存放在新根的右边
void turn_left(struct node **head); //原根节点的右节点成为新根节点，原根节点存放在新根的左边

void balance(struct node **head);
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

	getchar();

	balance(&head);
	print_tree(head, 0, 0);

}

void balance(struct node **head)
{
	int lc, rc;
	if (NULL == *head)
		return;

	while (1)
	{
		lc = count_node((*head)->left);
		rc = count_node((*head)->right);
		if (abs(lc-rc) <= 1)
			break;
		if ((lc - rc) > 1)
			turn_right(head);
		else
			turn_left(head);
	}

	balance(&(*head)->left);
	balance(&(*head)->right);
}

//原根节点的右节点成为新根节点，原根节点存放在新根的左边
void turn_left(struct node **head)
{
	struct node *new_head, *tmp, *l, *r;

	if (NULL == (*head)->right)
		return;

	new_head = (*head)->right;
	(*head)->right = NULL;

	l = new_head->left;
	if (NULL == l)
		new_head->left = *head;
	else
	{
		while (NULL != l->left)
			l = l->left;
		l->left = *head;
	}	
	*head = new_head;
}

//原根节点的左节点成为新根节点，原根节点存放在新根的右边
void turn_right(struct node **head)
{
	struct node *new_head, *tmp, *l, *r;

	if (NULL == (*head)->left)
		return;

	new_head = (*head)->left;
	(*head)->left = NULL;

	r = new_head->right;
	if (NULL == r)
		new_head->right = *head;
	else
	{
		while (NULL != r->right)
			r = r->right;
		r->right = *head;
	}	
	
	*head = new_head;
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
