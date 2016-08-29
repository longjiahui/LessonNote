
#include <stdio.h>

#define  ROW  9
#define  COL  9

#define   NONE    0x0
#define   BLACK   1
#define   WHITE   -1

int array[ROW][COL] = {0};

void Show_BackGround(void);

int main(void)
{

	
	int row , col ; 

	int flag = 1 ;   //黑方

	row = 0 ; 
	col = 0 ; 

	Show_BackGround();

	while(1)
	{
		scanf("%d%d" , &row , &col);
		array[row][col] = flag ; 
		Show_BackGround();
		flag = -flag ; 
	}

	return 0 ; 
}

void Show_BackGround(void)
{
	int i , j ; 
	system("clear");
	for(i = 0 ; i < ROW ; i++)
	{
		for(j = 0 ; j < COL ; j++)
		{
			if(array[i][j] == NONE)
			{
				printf("+ ");
			}else if(array[i][j] == BLACK)
			{
				printf("# ");
			}else
			{
				printf("@ ");
			}
   		}
		putchar('\n');
   	}
	fflush(stdout);
}
	

