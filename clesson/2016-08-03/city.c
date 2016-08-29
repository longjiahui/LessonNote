
#include <stdio.h>
#include "city.h"

enum
{
UP,
DOWN,
LEFT,
RIGHT,
UNKNOWN,
ESC,
};

int StartIndex = 0 ; 

void Show_Menu(int index);
int Get_User_Input(int *index);
int main(void)
{

	int index = 0 ; 

	while(1)
	{
		Show_Menu(index);
		if(Get_User_Input(&index))
			break;
	}

	return 0 ; 
}

void Show_Menu(int index)
{
	int row ; 
	system("clear");
	for(row = 0 ; row < 7; row++)
	{
		if(index == row)
			printf("\033[30m\033[47m\033[%d;30H%s\033[0m" ,5+row , city[(row+StartIndex)%NR(city)]);
		else
			printf("\033[37m\033[40m\033[%d;30H%s\033[0m" ,5+row , city[(row+StartIndex)%NR(city)]);
	}
	fflush(stdout);
}

static int _Get_User_Input(void)
{
	int type ; 
	char ch ; 

	type = UNKNOWN ; 

	system("stty -icanon");
	system("stty -echo");

	ch = getchar();
	if(ch == 'q')
	{
		type = ESC ; 
	}

	if((ch == '\033') && (getchar() == '['))
	{
		switch(getchar())
		{
		case  'A' : type = UP ; break;
		case  'B' : type = DOWN; break;
		case  'C' : type = RIGHT; break;
		case  'D' : type = LEFT; break;
		}
	}

	system("stty icanon");
	system("stty echo");

	return type ; 
}


int Get_User_Input(int *index)
{
	int type ; 
	
	type = _Get_User_Input();

	switch(type)
	{
		case  UP: if(*index > 0) *index-=1 ; 
				  else
					StartIndex=(StartIndex-1+NR(city))%NR(city);
		break;
		case  DOWN: if(*index < 6)  *index += 1 ; 
				  else
					StartIndex=(StartIndex+1)%NR(city);
		break;
		case LEFT : StartIndex=(StartIndex-7+NR(city))%NR(city); break;
		case RIGHT: StartIndex=(StartIndex+7)%NR(city);          break;
		case ESC  :  return 1 ; 
	}

	return 0 ; 
}

