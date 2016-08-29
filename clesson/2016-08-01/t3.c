
#include <stdio.h>

static int array[5] = {1,2,3,4,5};

enum
{
	UNKNOWN,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	ESC,
};

void show_array(void);
int Get_User_Input(void);
void turn_over(void);
void turn_left(void);
void turn_right(void);

int main(void)
{

	system("clear");
	while(1)
	{
		show_array();
		if(Get_User_Input())
			break;
	}

	return 0 ; 
}
void show_array(void)
{
	int i ; 
	for(i = 0 ; i < 5 ; i++)
	{
		printf("%d " , array[i]);
	}
	putchar('\n');
}

static int _Get_User_Input(void)
{
	int type ; 
	type = UNKNOWN ; 
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
		case 'A' : type = UP ; break;
		case 'B' : type = DOWN; break;
		case 'C' : type = RIGHT; break;
		case 'D' : type = LEFT; break;
		}
	}
	system("stty echo");
	system("stty icanon");
	return type ; 
}

int Get_User_Input(void)
{
	int type ; 
	type = _Get_User_Input();

	switch(type)
	{
		case UP:   turn_over();  break;
		case DOWN: turn_over();  break;
		case LEFT: turn_left();  break;
		case RIGHT:turn_right(); break;
		case ESC:   return 1 ; 
	}

	return 0 ; 
}

void turn_over(void)
{
	int i ; 
	int tmp ; 
	for(i = 0 ; i < 5/2 ; i++)
	{
		tmp = array[i];
		array[i]=array[4-i];
		array[4-i]=tmp;
	}
}
void turn_left(void)
{
	int tmp ; 
	int i ; 
	
	tmp = array[0];
	#if 0
	for(i = 0 ;  i < 4 ; i++)
	{
		array[i] = array[i+1];
	}
	#endif
	for(i = 1 ; i < 5 ; i++)
	{
		array[i-1] = array[i];
	}
	array[4]=tmp ; 
}
void turn_right(void)
{
	int tmp ; 
	int i ; 
	
	tmp = array[4] ; 
	#if 0
	for(i = 4 ; i > 0 ; i--)
	{
		array[i] = array[i - 1 ];
	}
	#endif
	for(i = 3 ; i>=0 ; i--)
	{
		array[i+1] = array[i];
	}

	array[0] = tmp ; 
}
