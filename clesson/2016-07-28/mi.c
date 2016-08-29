#include <stdio.h>
#include <stdlib.h>

#define NR(x) (sizeof(x) / sizeof(x[0]))
#define N   24
#define  msleep(x)    (usleep(1000*x))

// 地图
static int map[N][N] = {
  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
  5,0,5,0,0,0,0,0,0,0,0,5,5,0,5,0,0,0,0,0,0,0,0,5,
  5,0,5,5,5,5,5,5,5,0,5,5,5,0,5,5,5,5,5,5,5,0,5,5,
  5,0,5,0,5,0,5,0,0,0,5,5,5,0,5,0,5,0,5,0,0,0,5,5,
  5,0,5,0,5,0,5,0,5,5,5,5,5,0,5,0,5,0,5,0,5,5,5,5,
  5,0,5,0,5,0,0,0,5,0,0,5,5,0,5,0,5,0,0,0,5,0,0,5,
  5,0,5,0,5,0,5,0,5,5,0,5,5,0,5,0,5,0,5,0,5,5,0,5,
  5,0,0,0,0,0,5,0,0,0,0,5,5,0,0,0,0,0,5,0,0,0,0,5,
  5,0,5,5,5,0,5,5,5,5,5,5,5,0,5,5,5,0,5,5,5,5,5,5,
  5,0,5,0,5,0,0,0,5,0,0,0,0,0,5,0,5,0,0,0,5,0,0,5,
  5,0,0,0,5,0,5,0,0,0,5,5,5,0,0,0,5,0,5,0,0,0,5,5,
  5,5,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,5,5,
  5,5,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,5,5,
  5,0,5,0,0,0,0,0,0,0,0,5,5,0,5,0,0,0,0,0,0,0,0,5,
  5,0,5,5,5,5,5,5,5,0,5,5,5,0,5,5,5,5,5,5,5,0,5,5,
  5,0,5,0,5,0,5,0,0,0,5,5,5,0,5,0,5,0,5,0,0,0,5,5,
  5,0,5,0,5,0,5,0,5,5,5,5,5,0,5,0,5,0,5,0,5,5,5,5,
  5,0,5,0,5,0,0,0,5,0,0,5,5,0,5,0,5,0,0,0,5,0,0,5,
  5,0,5,0,5,0,5,0,5,5,0,5,5,0,5,0,5,0,5,0,5,5,0,5,
  5,0,0,0,0,0,5,0,0,0,0,5,5,0,0,0,0,0,5,0,0,0,0,5,
  5,0,5,5,5,0,5,5,5,5,5,5,5,0,5,5,5,0,5,5,5,5,5,5,
  5,0,5,1,5,0,0,0,5,0,0,5,5,0,5,0,5,0,0,0,5,0,2,5,
  5,0,0,0,5,0,5,0,0,0,5,5,5,0,0,0,5,0,5,0,0,0,5,5,
  5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
};

void show_mi(int *row , int *col);
int run_mi(int row , int col);

int main(void)
{
	int row , col ; 
	int  tmp1 , tmp2 ; 
	show_mi(&row , &col);
	


    return 0;
}

void show_mi(int *row , int *col)
{
	system("clear");
	int i , j ; 
	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < N ; j++)
		{
			if(map[i][j] == 5)
				printf("\033[%d;%dH\033[42m \033[0m" , i+5 , j+5);
			else if(map[i][j] == 1)
			{
				*row = i ; 
				*col = j ; 
				printf("\033[%d;%dH*" , i+5 , j+5);
			}
			else if(map[i][j] == 2)
				printf("\033[%d;%dHE" , i+5 , j+5);
			else if(map[i][j] == 3)
				printf("\033[%d;%dH\033[44m \033[0m" , i+5 , j+5);
			
		}
		putchar('\n');
	}
	fflush(stdout);
}
