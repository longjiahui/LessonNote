
#include <stdio.h>
#include <stdlib.h>

// 哈希

//把一个链表分成多个子链表， 用一指针变量数据存放子链表头

typedef struct node {
	int data;
	struct node *next;
}node_t;

node_t  heads[100] = {{0,NULL}}; //  100上链表头, 用户输入的数取100余数 作为数据的下标， 并把用户这个数存入相应的链表里.
// 用户需查一个数时， 取这个数的100余数作为链表数组的下标， 再在相应的链表里遍历

int main(void)
{
	int num;
	node_t *new, *tmp;

	while (1)
	{
		printf("input num: ");
		scanf("%d", &num);
		
		if (num < 0)
			break;
		
		new = malloc(sizeof(node_t));
		new->data = num;
		
		//加入相应的链表
		new->next = heads[num%100].next;
		heads[num%100].next = new;
	}
	
	printf("input num to find :");
	scanf("%d", &num);
		
	for (tmp = heads[num%100].next; tmp != NULL; tmp = tmp->next)
	{
		if (tmp->data == num)
		{
			printf("found: %d\n", num);
			break;
		}
	}
	
	



	return 0;
}

