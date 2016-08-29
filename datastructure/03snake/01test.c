
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOOD_COLOR  43
#define SNAKE_COLOR 44

typedef struct {
	int x;
	int y;
}point_t;

void draw_point(point_t p, int color);
int main(void)
{
	point_t food , snake_head;

	srand((int)&food);
	
	food.x = random()%50;
	food.y = random()%50;
	
	snake_head.x = random()%50;
	snake_head.y = random()%50;
		
	printf("\033[2J");
	
	draw_point(food, FOOD_COLOR);
	draw_point(snake_head, SNAKE_COLOR);


	printf("\033[0m");
	return 0;
}

void draw_point(point_t p, int color)
{
	printf("\033[%d;%dH", p.y, p.x);

	printf("\033[%dm  ", color);
}
