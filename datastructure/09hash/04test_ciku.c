
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN  100

struct node {
	char *chn;
	char *eng;

	struct node *next;
};

struct node heads[LEN];
int         count[LEN];

int get_index(char *eng);
int main(void)
{
	FILE *fl;
	char line_eng[200];
	char line_chn[200];
	struct node *new, *tmp;
	int index;

	fl = fopen("./ciku.dict", "r");
	if (NULL == fl)
	{
		perror("fopen");
		return 1;
	}

	while (1)
	{
		if (NULL == fgets(line_eng, sizeof(line_eng), fl))
			break;
		if (NULL == fgets(line_chn, sizeof(line_chn), fl))
			break;
		//去掉换行符
		line_eng[strlen(line_eng)-1] = '\0';
		line_chn[strlen(line_chn)-1] = 0;

		new = malloc(sizeof(*new));
		new->eng = malloc(strlen(line_eng));	
		strcpy(new->eng, line_eng);

		new->chn = malloc(strlen(line_chn));	
		strcpy(new->chn, line_chn);
		
		index = get_index(line_eng);
		new->next = heads[index].next;
		heads[index].next = new;
		count[index]++;
	}

	int i, sum = 0;
	for (i = 0; i < LEN; i++)
	{
		printf("%d: %d\n", i, count[i]);
		sum += count[i];
	}
	printf("sum = %d\n", sum);

	while (1)
	{
		printf("input word to find: ");
		scanf("%s", line_eng);
		
		if (strcmp("exit", line_eng) == 0)
			break;
			
		index = get_index(line_eng);
		for (tmp = heads[index].next; tmp != NULL; tmp = tmp->next)
		{
			if (strcmp(line_eng, tmp->eng) == 0)
				printf("%s : %s\n", tmp->eng, tmp->chn);
		}
	}
	return 0;
}

int get_index(char *eng)
{
	unsigned long sum = 0;
	char *p = eng;
	
	while (*p)
		sum += *p++;

	return sum%LEN;
}
