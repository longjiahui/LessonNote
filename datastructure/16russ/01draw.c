

#include <stdio.h>

char block[4][4] = {
	{1, 1, 0, 0},
	{0, 1, 0, 0},
	{0, 1, 1, 1},
	{0, 0, 0, 1},
};


int main(void)
{
	int i, j;

	printf("\033[2J");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (block[i][j])
				printf("\033[44m  ");
			else
				printf("\033[0m  ");
		}
		printf("\n");
	}


	printf("\33[0m");
	return 0;
}
