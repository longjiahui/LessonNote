
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

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

enum
{
	LEFT,
	RIGHT,
	UNKNOWN,
	ESC,
};

//time

#define  msleep(x)     usleep((x)*1000)

//框的大小
#define  ROW          25
#define  COL          90
#define  LENGTH       30   //棍子长度
#define  OFFSET       10
//NR
#define  NR(x)     (sizeof(x)/sizeof(x[0]))

int index  = 0; 


//*************************************************
//子线程函数

void Show_Circle(void);
void Show_Block(struct Block *Array , int SIZE);
void Clear_Block(struct Block *Array , int SIZE);
void Move_Block(struct Block *Array , int SIZE);
void Init_Array(struct Block *Array , int SIZE);

//*************************************************
//主线程函数
void Show_Stick(int index);
void Clear_Stick(void);
int  Get_User_input(int *index);

//*************************************************
//线程处理函数

void *do_thread(void *arg);

int main(void)
{

	int number ; 

	printf("Pls input Number blocks: \n");
	scanf("%d" , &number);
	if((number <= 0) || (number > 100000))
	{
		fprintf(stderr , "The Input Number is Out of Range \n");
		return -1 ; 
	}

	pthread_t  tid ; 
	int ret ; 
	ret = pthread_create(&tid , NULL , do_thread , (void *)number);

	//创建一条线程

	while(1)
	{
		Clear_Stick();
		Show_Stick(index);
		if(Get_User_input(&index))
			break;
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
//		printf("\033[%d;%dH\033[45m \033[0m" ,ROW, col);
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
	//if((block->Row == 2) || (block->Row + block->Size == ROW))
	if(block->Row == 2)
		block->Drow = -block->Drow ; 
	//检查如果碰到棍子就返回
	if(block->Row + block->Size == ROW)
	{
		if(((block->Col>=index) && (block->Col <= index+LENGTH))
||(((block->Col+block->Size*2 >=index)&&(block->Col+block->Size*2 <= index+LENGTH))))
		{
			block->Drow = -block->Drow ; 
		}
	}

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


void *do_thread(void *arg)
{
	int number = (int)arg ; 

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
}

void Show_Stick(int index)
{
	//ROW
//	printf("\033[%d;%dH\033[45m \033[0m" ,ROW, col);
	int i ; 
	for(i = 0 ; i < LENGTH ; i++)
	{
		printf("\033[%d;%dH\033[45m \033[0m" ,ROW, i+index);
	}
}

void Clear_Stick(void)
{
	int i ; 	
	for(i = 0 ; i < COL ; i++)
	{
		printf("\033[%d;%dH " ,ROW, i);
	}
}

static int _Get_User_Input(void)
{
	int type = UNKNOWN ; 
	char ch ; 

	system("stty -echo");
	system("stty -icanon");

	ch = getchar();
	if(ch == 'q')
		type = ESC ; 
	if(ch == '\033' && getchar() == '[')
	{
		switch(getchar())
		{
		case 'C' : type = RIGHT ; break;
		case 'D' : type = LEFT  ; break;
		}
	}

	system("stty echo");
	system("stty icanon");

	return type ; 
}


int  Get_User_input(int *index)
{
	int type ; 
	type = _Get_User_Input();

	switch(type)
	{
		case  LEFT : if(*index > 0) *index-=OFFSET ;  break;
		case RIGHT : if(*index + LENGTH < COL)  *index+=OFFSET ;  break;
		case UNKNOWN :break;
		case ESC   :  return 1 ; 
	}

	return 0 ; 
}



