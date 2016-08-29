
//做一个方块,可以通过键盘控制

#include <stdio.h>

int  row  ; 
int  col  ; 
int  drow ; 
int  dcol ; 

#define   ROW  4
#define   COL  8
#define   STARTROW   10
#define   STARTCOL   10
 
void Show_Block(void);       

int main(void)
{

	row = STARTROW ;
	col = STARTCOL ; 
	drow = 1 ; 
	dcol = 1 ; 

	printf("\033[?25l");
	system("clear");
	while(1)
	{//有死循环肯定要写退出条件
	//如果有人按键盘q就退出
	
		system("clear");
		Show_Block();
		row+=drow ;
		col+=dcol ; 

		if((row >= 25) || (row == 1))	
		{
			drow = -drow ; 
		}
		if((col == 1) || (col >= 88))
		{
			dcol = -dcol ; 
		}

		//sleep(1);
		usleep(1000*10);
	}
	printf("\033[?25h");


	return 0 ; 
}

void Show_Block(void)
{
	int i , j ; 
	for(i = 0 ; i < ROW ; i++)
	{
		for(j = 0 ;j < COL ; j++)
		{
			printf("\033[%d;%dH\033[43m \033[0m" , row+i , col+j);
		}
	}
	//刷缓冲区
	fflush(stdout);
}

