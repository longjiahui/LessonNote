

#include <stdio.h>

char block[4][4] = {
	{1, 1, 0, 0},
	{0, 1, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 0, 0},
};

void show_block(int x, int y);
void clear_block(int x, int y);
int main(void)
{
	int i, j;
	int x = 30, y = 20;
	char ch;

	printf("\033[2J");
	system("stty -echo -icanon");
	
	while (1)
	{	
		ch = getchar();
		if ('\033' != ch)
			continue;
		if ('[' != getchar())
			continue;

		clear_block(x, y);
		switch (getchar())
		{
		case 'A':
			y--;
			break;
		case 'B':
			y++;
			break;
		case 'C':
			x++;
			break;
		case 'D':
			x--;
			break;
		}
		show_block(x, y);
	}
	system("stty echo icanon");
	printf("\033[0m");
	return 0;
}
/*
@@@@ 
@@@@
@@@@
@@@@

	    @@@@
	    @@@@
	    @@@@
            @@@@
*/

void clear_block(int x, int y)
{
	int i, j;
	for (i = 0; i < 4; i++) //行
	{
		for (j = 0; j < 4; j++)
		{
			printf("\033[%d;%dH", y+i, x+(j*2));
			if (block[i][j])
				printf("\033[0m  ");
		}
	}
}

void show_block(int x, int y)
{
	int i, j;
	
	for (i = 0; i < 4; i++) //行
	{
		for (j = 0; j < 4; j++)
		{
			printf("\033[%d;%dH", y+i, x+(j*2));
			if (block[i][j])
				printf("\033[44m  ");
			else
				printf("\033[0m  ");
		}
		printf("\033[0m\n");
	}
	fflush(NULL);
}
