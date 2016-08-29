
#include <stdio.h>
#include <stdlib.h>

#define LEN 10

int main(void)
{
	int i, j;
	int num[LEN];

	srand((long)&i);

	for (i = 0; i < LEN; i++)
	{
		num[i] = random()%100;
		printf("%02d ", num[i]);
	}
	printf("\n");
//////////////////////////
	int tmp, k;

	for (i = 0; i < LEN; i++)
	{
		for (j = 0; j < LEN-i-1; j++)
		{
			if (num[j] > num[j+1])
			{
				tmp = num[j];
				num[j] = num[j+1];
				num[j+1] = tmp;

				printf("sort %d:", i);
				for (k = 0; k < LEN; k++)
					printf("%02d ", num[k]);
				printf("\n");
				getchar();
			}	
		}
	}
	printf("after sort:\n");
	for (i = 0; i < LEN; i++)
	{
		printf("%02d ", num[i]);
	}
	printf("\n");
	return 0;
}
