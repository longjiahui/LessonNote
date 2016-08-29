
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

int compare(const void *arg1, const void *arg2); // 快速排序用的比较函数
void print_tree(node_t *head, struct char_t *chars, int level, int type); //打印二叉树
void create_tree(node_t **head, struct char_t *chars); //根据排好序的chars数组生成相应的二叉树
int find_char(node_t *head, struct char_t *chars, int ch, char *codes, int level);
int main(void)
{
	FILE *fl;
	unsigned char ch;
	struct char_t *chars;
	node_t *tree;
	int i; 
	int	count = 0; //用于记录共有多少个字符
	int     num = 0; //用于记录多个字符有用到的, chars数组里有效元素个数

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
		count++;
	}

	qsort(chars, LEN, sizeof(*chars), compare); //注意排完序后，数组元素的位置会发生改变，所以不能再使用数组下标表示相应的字符了	
	create_tree(&tree, chars); //根据排好序的chars数组生成相应的二叉树
	print_tree(tree, chars, 0, 0);

	for (i = 0; i < LEN ; i++)
	{
		if (chars[i].count == 0)
			continue;

		num++;
		ch = chars[i].ch; //要进行编码的字符
		find_char(tree, chars, ch, codes[ch].data, 0);
		printf("%c: %s\n", ch, codes[ch].data);
	}
	//最终编码表存放在codes数组里，以字符为下标即可取到相应的编码

	unsigned char data = 0;
	unsigned char *p;
	int bits = 0; //记录已存放的数据位数
	FILE *fl_dst;	

	fl_dst = fopen("./data_encoded.txt", "w+");
	fprintf(fl_dst, "%d,%d", count, num);
	fwrite(chars+(LEN-num), sizeof(*chars), num, fl_dst);
	//编码出的文件存放内容： 字符个数,生成二叉树的数组元素个数+chars数组里的有效元素数据+编码出来的内容


	fseek(fl, 0, SEEK_SET); //rewind(fl)
	
	while (1)
	{
		ch = fgetc(fl);
		if (feof(fl))
			break;

		p = codes[ch].data;
		while (*p)
		{
			if ('1' == *p)
				data |= 1<<(7-bits);
			else
				data &= ~(1<<(7-bits));
			bits++;
			if (8 == bits)
			{
				fputc(data, fl_dst);
				data = 0;
				bits = 0;
			}
			p++;
		}
	}
	if (bits) //如还有数据未满8位，则也需存放
		fputc(data, fl_dst);
	
	fclose(fl);
	fclose(fl_dst);
	
	

	return 0;
}

int find_char(node_t *head, struct char_t *chars, int ch, char *codes, int level)
{
	int ret = 0;

	if (NULL == head)
		return ret;

	if (chars[head->index].ch == ch)
	{
		codes[level] = '\0';
		return 1;
	}

	if (!ret)
	{
		codes[level] = '0';
		ret = find_char(head->left, chars, ch, codes, level+1);
	}

	if (!ret)
	{
		codes[level] = '1';
		ret = find_char(head->right, chars, ch, codes, level+1);
	}
	return ret;
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

