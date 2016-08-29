

#include <stdio.h>

struct block {
	char data[4][4]; //记录方块内容
	int  next;       //变形到哪个索引号
	
}blocks[] = {
	{.data = {
	  {0, 0, 0, 0},
	  {1, 1, 0, 0},
	  {0, 1, 0, 0},
	  {0, 1, 0, 0}},
	 .next = 1},    // 7
	{.data = {
	  {0, 0, 0, 0},
	  {0, 0, 0, 0},
	  {0, 0, 1, 0},
	  {1, 1, 1, 0}},
	  .next = 2},   //  7顺时针翻转90度
	{.data = {
	  {0, 0, 0, 0},
	  {1, 0, 0, 0},
	  {1, 0, 0, 0},
	  {1, 1, 0, 0}},
	 .next = 3},    // L
	{.data = {
	  {0, 0, 0, 0},
	  {0, 0, 0, 0},
	  {1, 1, 1, 0},
	  {1, 0, 0, 0}},
	 .next = 0},    // 
};

#define ROWS  15
#define COLS  20

char bg[ROWS][COLS]; //数组用于存放方块数据

void fill_block(int num, int x, int y); //把索引号为num的方块填入数组bg. x和y是在数组bg的坐标
void clear_block(int num, int x, int y); //从数组bg清除方块

void show_bg();
void show_bg_num(); //debug

int main(void)
{
	int x = 14, y = 0; //在数组bg的坐标
	int index = 0;
	char ch;

	printf("\033[2J");
	system("stty -echo -icanon");
	
	fill_block(index, x, y);
	while (1)
	{	
		show_bg();
		show_bg_num();

		ch = getchar();
		if (' ' == ch) //变形
		{
			clear_block(index, x, y);
			index = blocks[index].next;
			fill_block(index, x, y);
			continue;
		}

		if ('\033' != ch)
			continue;
		if ('[' != getchar())
			continue;

		clear_block(index, x, y);
		switch (getchar())
		{
		case 'A':
			y--;
			break;
		case 'B':
			y++;
			if ((y+4) > ROWS)
			{
				fill_block(index, x, y-1);
				//新的方块
				index = 0;
				x = 14;
				y = 0;
			}
			break;
		case 'C':
			x++;
			break;
		case 'D':
			x--;
			break;
		}
		fill_block(index, x, y);
		

	}
	system("stty echo icanon");
	printf("\033[0m");
	return 0;
}

void clear_block(int n, int x, int y)
{
	int i, j;
	for (i = 0; i < 4; i++) //行
	{
		for (j = 0; j < 4; j++)
		{
			if (blocks[n].data[i][j])
				bg[y+i][x+j] = 0;
		}
	}
}

void fill_block(int n, int x, int y)
{
	int i, j;
	
	for (i = 0; i < 4; i++) //行
	{
		for (j = 0; j < 4; j++)
		{
			if (blocks[n].data[i][j])
				bg[y+i][x+j] = 1;
		}
	}
}

void show_bg() //根据数组里值刷出所有存放的方块数据
{
	int i, j;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("\033[%d;%dH", i, j*2);
			if (bg[i][j])
				printf("\033[44m  ");
			else
				printf("\033[0m  ");
		}
		printf("\033[0m\n");
	}

	fflush(NULL);
}

#define LEN_X  55
void show_bg_num() //debug
{
	//把数组bg里的值打印出来
	int i, j;

	for (i = 0; i < ROWS; i++)
	{
		printf("\033[%d;%dH", i, LEN_X);
		for (j = 0; j < COLS; j++)
		{	
			printf("%d", bg[i][j]);
		}
		printf("\033[0m\n");
	}
	fflush(NULL);
}

