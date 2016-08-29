
#include <stdio.h>
#include <stdlib.h>

char maze[][100] = {
	"###################################",
	"#  #   #   # #                    #",
	"#      #        #  ## #######     #",
	"#  #      #  #              #  # @#",
	"###################################",
};

// '#'表示迷宫的墙, '@'表示目标, '$'表示走过的路
void show();
void move(int x, int y);
int main(void)
{
	move(1, 1); //从第1行的第1个字符开始出发	
	return 0;
}

void move(int x, int y)
{
	if (maze[y][x] == '@')
	{
		printf("found \n");
		exit(0);
		return;
	}
	if (maze[y][x] != ' ')
		return;

	maze[y][x] = '$';
	show();
	getchar();
	///

	move(x+1, y);
	move(x, y+1);
	move(x-1, y);
	move(x, y-1);
	
	maze[y][x] = ' ';
	show();
	getchar();
}

void show()
{
	int y;
	printf("\033[2J");

	for (y = 0; y < 5; y++)
		printf("%s\n", maze[y]);

}
