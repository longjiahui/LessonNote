
#include <stdio.h>
#include <unistd.h>

extern char **environ;
int main(int argc, char *argv[])
{
	int i;

	printf("in mytest:\n");
	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);

	return 0;
	printf("enviroment: \n");

	for (i = 0; NULL != environ[i]; i++)
		printf("%s\n", environ[i]);

	return 0;
}
