
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//time

#define  msleep(x)     usleep((x)*1000)

//框的大小
#define  ROW          25
#define  COL          90
//NR
#define  NR(x)     (sizeof(x)/sizeof(x[0]))

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
void Show_Block(struct Block *Array , int SIZE);
void Clear_Block(struct Block *Array , int SIZE);
void Move_Block(struct Block *Array , int SIZE);
void Init_Array(struct Block *Array , int SIZE);

int main(void)
{
//	struct Block block = {10,20,2,43,1,1}; 

	int number ; 

	printf("Pls input Number blocks: \n");
	scanf("%d" , &number);
	if((number <= 0) || (number > 100000))
	{
		fprintf(stderr , "The Input Number is Out of Range \n");
		return -1 ; 
	}

	struct Block  Array[number] ;

	srand(time(NULL));
	Init_Array(Array , number);

	printf("\033[?25l");
	Show_Circle();

	while(1)
	{
		//刷
		Show_Block(Array , number);
		//睡
		msleep(50);
		//清
		Clear_Block(Array , number);
		//走
		Move_Block(Array , number);
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

static void _Show_Block(struct Block block)
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

void Show_Block(struct Block *Array , int SIZE)
{
	int i ; 
	for(i = 0 ;i < SIZE ; i++)
	{
		_Show_Block(Array[i]);
	}
}

static void _Clear_Block(struct Block block)
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

void Clear_Block(struct Block *Array , int SIZE)
{
	int i ; 
	for(i = 0 ; i < SIZE ; i++)
	{
		_Clear_Block(Array[i]);
	}
}


static void _Move_Block(struct Block *block)
{
	if((block->Row == 2) || (block->Row + block->Size == ROW))
		block->Drow = -block->Drow ; 

	if((block->Col == 2) || (block->Col + block->Size*2== COL))
		block->Dcol = -block->Dcol ; 

	block->Row = block->Row + block->Drow ;
	block->Col = block->Col + block->Dcol ; 
}

void Move_Block(struct Block *Array , int SIZE)
{
	int i ; 
	for(i = 0 ; i < SIZE ; i++)
	{
		_Move_Block(&(Array[i]));
	}
}

static void _Init_Array(struct Block *block)
{
	//获取随机值
	block->Row = (rand() % (ROW-6))+3 ;
	block->Col = (rand() % (COL-10))+3 ; 
	block->Color = rand() % 8 + 40 ;
	block->Size =  rand() % 3 + 1 ; 
	block->Drow = (rand() % 2)?1:-1; 
	block->Dcol = (rand() % 2)?1:-1; 
}

void Init_Array(struct Block *Array , int SIZE)
{
	int i ; 
	for(i = 0 ; i < SIZE ; i++)
	{
		_Init_Array(&(Array[i]));
	}
}






