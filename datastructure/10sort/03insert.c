
#include <stdio.h>

#define LEN 10

int main(void)
{
	int num[LEN];
	int i, j;
	int tmp;

	for (i = 0; i < LEN; i++)
	{
		num[i] = random()%100;
		printf("%02d ", num[i]);
	}
	printf("\n");
//////////////

	for (i = 0; i < LEN; i++)
	{
		for (j = i+1; j > 0; j--)
		{
			if (num[j] < num[j-1])
			{
				tmp = num[j-1];
				num[j-1] = num[j];
				num[j] = tmp;
			}
			else
				break;	
		}
	}

///////////////
	printf("after sort: ");
	for (i = 0; i < LEN; i++)
		printf("%02d ", num[i]);
	printf("\n");
	return 0;
}
