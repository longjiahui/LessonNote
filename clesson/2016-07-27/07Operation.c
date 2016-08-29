
//做一个方块,可以通过键盘控制

#include <stdio.h>

int  row  ; 
int  col ; 

#define   ROW  4
#define   COL  8
#define   STARTROW   10
#define   STARTCOL   10
#define   UP    0x01
#define   DOWN  0x02
#define   LEFT  0x03
#define   RIGHT 0x04
#define   ESC   0x05
#define   UNKNOWN 0x06
 
void Show_Block(void);       
int Get_User_Input(void);

int main(void)
{

	row = STARTROW ;
	col = STARTCOL ; 

	printf("\033[?25l");
	system("clear");
	while(1)
	{//有死循环肯定要写退出条件
	//如果有人按键盘q就退出
	
		system("clear");
		Show_Block();

		if(Get_User_Input())
			break;
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

int _Get_User_Input(void)
{ //获取按键

	int type ; 
	type = UNKNOWN ; 
	
	char ch ; 
	system("stty -echo");
	system("stty -icanon");

	ch = getchar();
	if(ch == 'q')
	{
		type = ESC ; 
	}
	if(ch == '\033' && getchar() == '[')
	{
		switch(getchar())
		{
		 case 'A'  : type = UP ;    break;
		 case 'B'  : type = DOWN;   break;
		 case 'C'  : type = RIGHT;  break;
		 case 'D'  : type = LEFT;   break;
		}
	}

	system("stty echo");
	system("stty icanon");

	return type ; 
}

int Get_User_Input(void)
{
	int type ;
	type = _Get_User_Input();  //子函数


	switch(type)
	{
	case UP : if(row > 0)  row-- ;   break;
	case DOWN: if(row < 25) row++ ;  break;
	case LEFT: if(col > 0) col-- ;   break;
	case RIGHT: if(col < 88) col++ ; break;
	case ESC : return 1 ; 
	}

	return 0 ; 
}
