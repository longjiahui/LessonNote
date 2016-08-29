
#include <stdio.h>
#include <stdlib.h>

struct mylist {
	int data;

	struct mylist *next;
};

//用链表来记录用户输入的数值， 个数不确定。直到输入的数为-1为止

int main(void)
{
	int num;
	struct mylist *head = NULL,  //用于存放链表的头节点地址
		      *new = NULL;   //用于存放新产生的节点地址

	while (1)
	{
		printf("input num:");
		scanf("%d", &num);

		if (num < 0)
			break;
		//产生一个链表的新节点，用于存放刚输入的值
		new = malloc(sizeof(*new));
		new->data = num;
		new->next = NULL;

		//加入链表去	
		if (NULL == head)
			head = new; //当没有头节点时，新节点则成为头节点
		else
		{
			new->next = head; //新的节点指向头节点		
			head = new;       //新节点作头节点
		}	
	}

	for (new = head; new != NULL; new = new->next)
	{
		printf("%d\n", new->data);
	}

	return 0;
}
