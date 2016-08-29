
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN  26

struct node {
	char *chn;
	char *eng;

	struct node *next;
};

struct node heads[LEN];
int main(void)
{
	FILE *fl;
	char line_eng[200];
	char line_chn[200];
	struct node *new, *tmp;

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
		
		new->next = heads[line_eng[0]%LEN].next;
		heads[line_eng[0]%LEN].next = new;
	}

	while (1)
	{
		printf("input word to find: ");
		scanf("%s", line_eng);
		
		if (strcmp("exit", line_eng) == 0)
			break;
			
		
		for (tmp = heads[line_eng[0]%LEN].next; tmp != NULL; tmp = tmp->next)
		{
	//		if (strncmp(line_eng, tmp->eng, strlen(line_eng)) == 0)
			if (strcmp(line_eng, tmp->eng) == 0)
				printf("%s : %s\n", tmp->eng, tmp->chn);
		}
	}
	return 0;
}
