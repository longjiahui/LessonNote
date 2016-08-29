
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOOD_COLOR  43
#define SNAKE_COLOR 44
#define BACK_COLOR  0

typedef struct {
	int x;
	int y;
}point_t;

void draw_point(point_t p, int color);
int main(void)
{
	point_t food , snake_head;

	srand((long)&food);
	
	food.x = random()%50/2*2; // 
	food.y = random()%50;
	
	snake_head.x = random()%50/2*2;
	snake_head.y = random()%50;
		
	printf("\033[2J");
	printf("\033[?25l"); // hide cursor
	
	draw_point(food, FOOD_COLOR);
	draw_point(snake_head, SNAKE_COLOR);
	

	system("stty -echo raw");
	
	char ch;
	while (1)
	{
		ch = getchar();
		if ('Q' == ch)
			break;
		
		if (ch != '\033')
			continue;
		
		if (getchar() != '[')
			continue;

		draw_point(snake_head, BACK_COLOR);
		switch (getchar())
		{
		case 'A':   // up
			snake_head.y--;
			break;
		case 'B':   //down
			snake_head.y++;
			break;
		case 'C':  // right
			snake_head.x += 2;
			break;
		case 'D':
			snake_head.x -= 2;
			break;
		}
		
		draw_point(snake_head, SNAKE_COLOR);
	}

	system("stty echo -raw");
	return 0;
}

void draw_point(point_t p, int color)
{
	printf("\033[%d;%dH", p.y, p.x);
	if (color != BACK_COLOR) 
	{
		printf("\033[%dm  ", color);
		printf("\033[0m");
	}
	else
		printf("  ");
}
