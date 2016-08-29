
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 256

//统计字符使用次数时用
struct char_t {
	int count;
	unsigned char ch; 	
};

//编码表
struct code_t {
	char data[LEN];  //存放字符对应的位编码， "110"表示二进制数据'3b110'
}codes[LEN];  //以字符为下标，存放字符相应的编码

//二叉树
typedef struct node {
	struct node *left, *right;
	int index; //对应chars数组的元素索引号	
	int val; //权重
}node_t;

void print_tree(node_t *head, struct char_t *chars, int level, int type); //打印二叉树
void create_tree(node_t **head, struct char_t *chars); //根据排好序的chars数组生成相应的二叉树
int main(void)
{
	FILE *fl;
	unsigned char ch;
	struct char_t *chars;
	node_t *tree, *tmp;
	int i; 
	int	count = 0; //用于记录共有多少个字符
	int     num = 0; //用于记录多个字符有用到的, chars数组里有效元素个数

	chars = malloc(sizeof(*chars)*LEN);
	memset(chars, 0, sizeof(*chars)*LEN);
	
	fl = fopen("./data_encoded.txt", "r");
	if (NULL == fl)
	{
		perror("fopen");
		return 1;
	}
	
	fscanf(fl, "%d,%d", &count, &num);
	fread(chars+(LEN-num), sizeof(*chars), num, fl);
	create_tree(&tree, chars); //根据排好序的chars数组生成相应的二叉树
	print_tree(tree, chars, 0, 0);

	//fl指向的文件再读就是编码出来的数据，还原方法，根据编码数据沿着二叉树从头开始走，如0往左走，1往右走，直到走到树的叶子为止，即是找到相应的字符。再接着从树头重新开始走
	FILE *fl_dst = fopen("./data_decoded.txt", "w+");	
	tmp = tree;
	while (1)
	{
		ch = fgetc(fl);
		if (feof(fl))
			break;
		for (i = 0; i < 8; i++)
		{
			if (ch & (1<<(7-i)))
				tmp = tmp->right;
			else
				tmp = tmp->left;		
			if ((NULL == tmp->left) && (NULL == tmp->right))
			{
//				printf("%c", chars[tmp->index].ch);
				fputc(chars[tmp->index].ch, fl_dst);
				tmp = tree;
				count--;
				if (0 == count)
					break;
			}
		}
	}
	fclose(fl_dst);
	fclose(fl);
	return 0;
}



void create_tree(node_t **head, struct char_t *chars)
{
	node_t *tmp = NULL, *new = NULL, *new_head = NULL;
	int i;
	
	//从使用次数不为0的字符开始创建二叉树
	i = 0; 
	while (chars[i].count == 0)
		i++;

	//创建第一个节点
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

	*head = new_head;
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

