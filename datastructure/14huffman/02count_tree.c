
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 256

struct char_t {
	int count;
	unsigned char ch;	
};

typedef struct node {
	struct node *left, *right;
	int index; //对应chars数组的元素索引号	
	int val; //权重
}node_t;

int compare(const void *arg1, const void *arg2);
void print_tree(node_t *head, struct char_t *chars, int level, int type);
int main(void)
{
	FILE *fl;
	unsigned char ch;
	struct char_t *chars;
	int i;

	chars = malloc(sizeof(*chars)*LEN);
	memset(chars, 0, sizeof(*chars)*LEN);
	
	for (i = 0; i < LEN; i++)
		chars[i].ch = i;

	fl = fopen("./data.txt", "r");
	if (NULL == fl)
	{
		perror("fopen");
		return 1;
	}

	while (1)
	{
		ch = fgetc(fl);
		if (feof(fl))
			break;
		chars[ch].count++; // 以字符作数组下标统计字符的使用次数
	}
	fclose(fl);

	qsort(chars, LEN, sizeof(*chars), compare); //注意排完序后，数组元素的位置会发生改变，所以不能再使用数组下标表示相应的字符了	
	////////
	for (i = 0; i < LEN; i++)
	{
		if (chars[i].count > 0)
			printf("%c : %d\n", chars[i].ch, chars[i].count);
	}

	//从使用次数不为0的字符开始创建二叉树
	node_t *tree = NULL, *tmp = NULL, *new = NULL, *new_head = NULL;
	i = 0; 
	while (chars[i].count == 0)
		i++;
	new = malloc(sizeof(node_t));
	new->left = NULL;
	new->right = NULL;
	new->index = i;
	new->val = chars[i].count;	

	i++;
	tmp = new;
	for (; i < LEN; i++)
	{
		new = malloc(sizeof(node_t));
		new->left = new->right = NULL;	
		new->index = i;
		new->val = chars[i].count;	

		new_head = malloc(sizeof(node_t));
		new_head->index = 0;
		new_head->val = tmp->val + new->val;
	
		if (tmp->val < new->val)
		{
			new_head->left = tmp;
			new_head->right = new;	
		}
		else
		{
			new_head->left = new;
			new_head->right = tmp;
		}

		tmp = new_head;	
	}

	tree = new_head;

	print_tree(tree, chars, 0, 0);
	return 0;
}

int compare(const void *arg1, const void *arg2)
{
	struct char_t *c1 = (struct char_t *)arg1;
	struct char_t *c2 = (struct char_t *)arg2;
	
	return c1->count - c2->count;
}

void print_tree(node_t *head, struct char_t *chars, int level, int type)
{
	int i;

	if (NULL == head)
		return;
	print_tree(head->right, chars, level+1, 2);	

	if (0 == type)
		printf("%c(%d)\n", chars[head->index].ch, head->val);
	if (1 == type) //左节点
	{
		for (i = 0; i < level; i++)
			printf("\t");
		printf("\\\n");
		
		for (i = 0; i < level; i++)
			printf("\t");
		printf("  %c(%d)\n", chars[head->index].ch, head->val);
	}
	if (2 == type)
	{
		for (i = 0; i < level; i++)
			printf("\t");
		printf("  %c(%d)\n", chars[head->index].ch, head->val);
		for (i = 0; i < level; i++)
			printf("\t");
		printf("/\n");
	}	

	print_tree(head->left, chars, level+1, 1);
}

