
#include <stdio.h>

#define  msleep(x)     usleep((x)*1000)

//框的大小
#define  ROW          25
#define  COL          90

//方块的属性
#define  W			  8
#define  H            4
#define  COLOR        43

struct Block
{
	//起始位置
	int Row ; 
	int Col ; 
	//大小
	int  Size ;   //高度
	//着色
	int  Color ; 
	//方向
	int Drow ; 
	int Dcol ; 
};

void Show_Circle(void);
void Show_Block(struct Block block);
void Clear_Block(struct Block block);
void Move_Block(struct Block *block);

int main(void)
{
	struct Block block = {10,20,2,43,1,1}; 

	printf("\033[?25l");
	Show_Circle();

	while(1)
	{
		//刷
		Show_Block(block);
		//睡
		msleep(50);
		//清
		Clear_Block(block);
		//走
		Move_Block(&block);
	}

	return 0 ;
}

void Show_Circle(void)
{
	system("clear");

	int  row , col ; 
		
	//最顶的一行
	for(col = 1 ; col < COL ; col++)
	{
		printf("\033[1;%dH\033[45m \033[0m" , col);
		printf("\033[%d;%dH\033[45m \033[0m" ,ROW, col);
	}
	
	for(row = 1 ; row <= ROW ; row++)
	{
		printf("\033[%d;1H\033[45m \033[0m" , row);
		printf("\033[%d;%dH\033[45m \033[0m" ,row, COL);
	}

	fflush(stdout);
}

void Show_Block(struct Block block)
{
	int i , j ; 
	for(i = 0 ; i < block.Size ; i++)
	{
		for(j = 0 ; j < block.Size*2; j++)
		{
			printf("\033[%d;%dH\033[%dm \033[0m" ,block.Row+i , block.Col+j,block.Color);
		}
	}
	fflush(stdout);
}

void Clear_Block(struct Block block)
{
	int i , j ; 
	for(i = 0 ; i < block.Size; i++)
	{
		for(j = 0 ; j < block.Size*2; j++)
		{
			printf("\033[%d;%dH " ,block.Row+i , block.Col+j);
		}
	}
	fflush(stdout);
}


void Move_Block(struct Block *block)
{
	if((block->Row == 2) || (block->Row + block->Size == ROW))
		block->Drow = -block->Drow ; 

	if((block->Col == 2) || (block->Col + block->Size*2== COL))
		block->Dcol = -block->Dcol ; 

	block->Row = block->Row + block->Drow ;
	block->Col = block->Col + block->Dcol ; 
}


