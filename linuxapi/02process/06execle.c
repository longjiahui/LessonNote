
#include <stdio.h>
#include <unistd.h>

extern char **environ;
int main(void)
{
	int ret, i;
	char *env[200] = {"AAA=aaa", "BBB=bbb", NULL};

	for (i = 0; NULL != environ[i]; i++)
	{
		env[i+2] = environ[i];
	}
	env[i+2] = NULL;


	ret = fork();
	if (0 == ret)
	{
		execle("./mytest", "11", "22", NULL, env);
	}

	printf("in main:\n");

	return 0;
}
