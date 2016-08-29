
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//用动态数组存放用户输入的数，直到负数为止

int main(void)
{
	int *num = NULL, count=0, *new = NULL;

	while (1)
	{
		new = malloc(sizeof(int)*(count+1));
		printf("input num:");
		scanf("%d", new+count);

		if (new[count] < 0)
			break;


		if (NULL != num)
		{
			memcpy(new, num, sizeof(int)*count); 
			free(num);
		}
		count++;


		num = new;
	}

	int i;
	for (i = 0; i < count; i++)
		printf("%d ", num[i]);
	printf("\n");
	
	free(num);
	return 0;
}


