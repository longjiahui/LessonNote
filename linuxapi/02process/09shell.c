
#include <stdio.h>
#include <unistd.h>

int split_string(char *str, char *argv[]);
int main(void)
{
	char line[1024], ch;
	int ret, num, i;
	char *argv[20];

	system("stty -echo -icanon");
	printf("\033[2J\n");

	printf("################################\n");
	printf("#                              #\n");
	printf("# welcome to myshell v9.9 !!   #\n");
	printf("#                              #\n");
	printf("################################\n\n");

	while (1)
	{
		printf("\nmyshell # ");
		num = 0;
		while ((ch = getchar()) != '\n')
		{
			line[num++] = ch;
			putchar(ch);
			fflush(NULL);
		}
		line[num] = 0;
//		printf("got: %s\n", line);

		num = split_string(line, argv);
		if (num <= 0)
			continue;

		ret = fork();
		if (0 == ret)
			execvp(argv[0], &argv[0]);
		wait(NULL);
	}
	
	system("stty echo icanon");
	return 0;
}

int split_string(char *str, char *argv[])
{
	// "   ls      -l    ./   "
	int num = 0;
	
	while (*str)
	{
		//处理前面的空格
		while ((*str) && (*str == ' '))
			str++;
		if (0 == *str)
			break;


		argv[num++] = str;
	
		//把词后面的空格改为尾0
		while ((*str) && (*str != ' '))
			str++;
		if (0 == *str)
			break;
		*str++ = 0;
	}
	argv[num] = NULL;
	return num;
}
