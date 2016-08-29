
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//用动态数组存放用户输入的数，直到负数为止
typedef struct {
	int id;
	char name[20];
}student_t;

int main(void)
{
	student_t *stus = NULL, *new = NULL;
	int count = 0, i;


	while (1)
	{
		new = malloc(sizeof(student_t)*(count+1));
		if (NULL != stus)
		{
			memcpy(new, stus, sizeof(student_t)*count);
			free(stus);
		}
		stus = new;

		printf("input id name:");
		scanf("%d  %s", &stus[count].id, stus[count].name);

		
		if (stus[count].id < 0)
			break;
		count++;
	}

	for (i = 0; i < count; i++)
		printf("%d  %s\n", stus[i].id, stus[i].name);

	
	free(stus);
	return 0;
}


