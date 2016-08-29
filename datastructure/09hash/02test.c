
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
	char *word;
	struct data *next;	
}data_t;

//static data_t  heads[26] = {{NULL, NULL}};
static data_t *heads;
int main(void)
{
	char word[100];
	data_t *new;

	heads = malloc(sizeof(data_t)*26);
	memset(heads, 0, sizeof(*heads)*26); //每个链表头置NULL

	while (1)
	{
		printf("input word: ");
		scanf("%s", word);
		
		if (strcmp("exit", word) == 0)
			break;
	
		new = malloc(sizeof(*new));
		new->word = malloc(strlen(word));
		strcpy(new->word, word);

		new->next = heads[word[0]-'a'].next;
		heads[word[0]-'a'].next = new;	
	}
///////////////
	char ch;
	data_t *tmp;



while (1)
{
	getchar(); //这里是处理掉前面输入的换行符
	printf("input char to find:");
	ch = getchar();
	
	for (tmp = heads[ch-'a'].next; tmp != NULL; tmp = tmp->next)
		printf("%s ", tmp->word);
	printf("\n");
}
	
	

	free(heads);
	return 0;
}

