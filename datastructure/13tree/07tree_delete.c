
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	
	struct node *left;
	struct node *right;
};
void show_tree(struct node *head, int type); // type 0前序，1中序，2后序
void print_tree(struct node *head, int level, int type);

void add_node(struct node **head, struct node *new);

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

	int num;
	struct node *prev, *new_head, *l, *n;
	while (1)
	{
		print_tree(head, 0, 0);
		printf("input data to delete:");
		scanf("%d", &num);
	
		tmp = head;
		prev = NULL;
		while (NULL != tmp)
		{
			if (num == tmp->data)
				break;
			
			prev = tmp;
			if (num > tmp->data) 
				tmp = tmp->right;
			else if (num < tmp->data)
				tmp = tmp->left;
		}
		if (NULL == tmp)
		{
			printf("no found\n");
			continue;
		}	

		//删除的节点， prev是要删除的节点的前一级节点, tmp为要删除的节点
		//1.如tmp的左右节点为空， prev指向tmp的指针置空， 删除tmp
		//2. 如tmp的右节点不为空， tmp->right上位, tmp->left挂在tmp->right最左边节点的left
		//3.如tmp的右节点为空，左节点不为空，tmp->left直接上位	

		if ((NULL == tmp->left) && (NULL == tmp->right)) // 1
			n = NULL;
		
		if (NULL != tmp->right) // 2
		{
			l = tmp->right->left;
			if (NULL == l)
				tmp->right->left = tmp->left;
			else
			{		
				while (NULL != l->left)
					l = l->left;
				l->left = tmp->left;
			}
			n = tmp->right;
		}	

		if (NULL == tmp->right) // 3
			n = tmp->left; 
	
		if (NULL != prev) //删除的不是根节点
		{	
			if (prev->left == tmp)
				prev->left = n;
			else
				prev->right = n;
		}
		else  //删除的是根节点
		{
			if (NULL == n)
				head = NULL; //要删除的根节点没有左右节点
			else
			{
				if (NULL != head->right)
					head = head->right;
				else
					head = head->left;	
			}
		}
		free(tmp);
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
