
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char line[1024], ch;
	int ret, num;

	system("stty  -icanon");
	printf("\033[2J\n");

	printf("################################\n");
	printf("#                              #\n");
	printf("# welcome to myshell v9.9 !!   #\n");
	printf("#                              #\n");
	printf("################################\n\n");

	while (1)
	{
		printf("myshell # ");
		num = 0;
		while ((ch = getchar()) != '\n')
			line[num++] = ch;
		line[num] = 0;
		printf("got: %s\n", line);


		
	}
	
	system("stty echo icanon");
	return 0;
}
