
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 256

struct char_t {
	int count;
	unsigned char ch;	
};


int compare(const void *arg1, const void *arg2);
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
	

	return 0;
}

int compare(const void *arg1, const void *arg2)
{
	struct char_t *c1 = (struct char_t *)arg1;
	struct char_t *c2 = (struct char_t *)arg2;
	
	return c1->count - c2->count;
}
