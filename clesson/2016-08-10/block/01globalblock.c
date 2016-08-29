
#include <stdio.h>

#define  msleep(x)     usleep((x)*1000)

#define  ROW          25
#define  COL          90
#define  W			  8
#define  H            4
#define  COLOR        43


void Show_Circle(void);
void Show_Block(int row , int col);
void Move_Block(int *row , int *col , int *drow , int *dcol);

int main(void)
{
	int drow , dcol ; 
	//方向
	drow = 1 ; 
	dcol = 1 ; 
	//起始位置
	int row , col ; 
	row = 10 ; 
	col = 10 ; 

	printf("\033[?25l");
	Show_Circle();

	while(1)
	{
		system("clear");
		Show_Circle();
		Show_Block(row , col);
		Move_Block(&row , &col , &drow , &dcol);
		msleep(50);
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

void Show_Block(int row , int col)
{
	int i , j ; 
	for(i = 0 ; i < H ; i++)
	{
		for(j = 0 ; j < W ; j++)
		{
			printf("\033[%d;%dH\033[%dm \033[0m" ,row+i , col+j,COLOR);
		}
	}
	fflush(stdout);
}

void Move_Block(int *row , int *col , int *drow , int *dcol)
{
	if((*row == 2) || (*row + H == ROW))
		*drow = -*drow ; 

	if((*col == 2) || (*col + W == COL))
		*dcol = -*dcol ; 

	*row = *row + *drow ;
	*col = *col + *dcol ; 
}


