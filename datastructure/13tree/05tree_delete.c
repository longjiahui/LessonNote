
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
	struct node *prev, *new_head, *l, *r;
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

		//找到后删除相应的节点
		if (NULL == prev) // 删除的是根节点
		{
			if ((NULL == head->left) && (NULL == head->right)) //只有一个根节点的情况
			{
				free(head);
				head = NULL;
				continue;
			}

			if (NULL != head->right)
				new_head = head->right;
			else
				new_head = head->left;
			
			if (NULL != head->right)
			{
				//原根节点的右节点做新根节点，原根的左节点挂在新根的最左节点下
				l = new_head->left;
				if (NULL == l)
					new_head->left = head->left;
				else
				{
					while (NULL != l->left)
						l = l->left;
					l->left = head->left; 
				}
			}
			//原根的左节点不为空, 原根的右节点为空, 则原根的左节点作新根
			free(head);	
			head = new_head;
			continue;
		}

		//删除的节点不是根节点， prev是要删除的节点的前一级节点, tmp为要删除的节点
		//1.如tmp的左右节点为空， prev指向tmp的指针置空， 删除tmp
		//2. 如tmp的右节点不为空， tmp->right上位, tmp->left挂在tmp->right最左边节点的left
		//3.如tmp的右节点为空，左节点不为空，tmp->left直接上位	

		if ((NULL == tmp->left) && (NULL == tmp->right)) // 1
		{
			if (prev->left == tmp)
				prev->left = NULL;
			else
				prev->right = NULL;
			continue;
		} 
		
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
			
			if (prev->left == tmp)
				prev->left = tmp->right;
			else
				prev->right = tmp->right;
			continue;
		}	

		// 3
		if (prev->left == tmp)
			prev->left = tmp->left;
		else
			prev->right = tmp->left;

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
