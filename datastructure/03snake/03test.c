
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOOD_COLOR  43
#define SNAKE_COLOR 44
#define BACK_COLOR  0

enum DIRE {
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

typedef struct {
	int x;
	int y;
}point_t;

typedef struct node {
	point_t p;

	struct node *next;
}node_t; 

void draw_point(point_t p, int color);
void add_node(node_t *body_head, point_t p);
void draw_snake(node_t *head);
void clear_snake(node_t *head);
void move_snake(node_t *head, enum DIRE direction); 

int main(void)
{
	point_t food ;
	node_t  head= {.next = NULL}; // head of snake

	srand((long)&food);
	
	food.x = random()%50/2*2; // 
	food.y = random()%50;
	
	head.p.x = random()%50/2*2;
	head.p.y = random()%50;

//////////
	point_t pp;
	pp.y = head.p.y;
	pp.x = head.p.x+8;
	add_node(&head, pp);
	pp.x = head.p.x+6;
	add_node(&head, pp);		
	pp.x = head.p.x+4;
	add_node(&head, pp);		
	pp.x = head.p.x+2;
	add_node(&head, pp);		
///////////////

	printf("\033[2J");
	printf("\033[?25l"); // hide cursor
	
	draw_point(food, FOOD_COLOR);

	draw_snake(&head);

	system("stty -echo -icanon");
	
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

		clear_snake(&head);
		switch (getchar())
		{
		case 'A':   // up
			move_snake(&head, UP);
			break;
		case 'B':   //down
			move_snake(&head, DOWN);
			break;
		case 'C':  // right
			move_snake(&head, RIGHT);
			break;
		case 'D':
			move_snake(&head, LEFT);
			break;
		}

		draw_snake(&head);
	}

	system("stty echo icanon");
	return 0;
}

void move_snake(node_t *head, enum DIRE direction)
{
	point_t prev, tmp;
	node_t *n;

	prev = head->p;
	for (n = head->next;	n != NULL; n = n->next)
	{
		tmp = n->p;
		n->p = prev;
		prev = tmp;
	}

	
	switch (direction)
	{
	case LEFT:
		head->p.x -= 2;
		break;
	case RIGHT:
		head->p.x += 2;
		break;
	case UP:
		head->p.y--;
		break;
	case DOWN:
		head->p.y++;
		break;
	}
}

void clear_snake(node_t *head)
{
	node_t *n;
	for (n = head; n != NULL; n = n->next)
	{
		printf("\033[%d;%dH", n->p.y, n->p.x);
		printf("\033[0m  ");
	}
}

void draw_snake(node_t *head)
{
	node_t *n;
	for (n = head; n != NULL; n = n->next)
	{
		printf("\033[%d;%dH", n->p.y, n->p.x);
		printf("\033[44m  ");
	}
	printf("\033[0m");
}

void add_node(node_t *body_head, point_t p)
{
	node_t *n = malloc(sizeof(node_t));

	n->p.x = p.x;
	n->p.y = p.y;

	n->next = body_head->next;
	body_head->next = n;
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
