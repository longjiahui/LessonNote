
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat buf;

	if (argc < 2)
	{
		printf("usage: ./a.out file_name \n");
		return 1;
	}

	stat(argv[1], &buf);

	if (S_ISDIR(buf.st_mode))
		printf("d");
	if (S_ISREG(buf.st_mode))
		printf("-");		
	if (S_ISCHR(buf.st_mode))
		printf("c");
	if (S_ISBLK(buf.st_mode))
		printf("b");
	
	if (buf.st_mode & S_IRUSR)
		printf("r");
	else
		printf("-");
	
	if (buf.st_mode & S_IWUSR)
		printf("w");
	else
		printf("-");

	if (buf.st_mode & S_IXUSR)
		printf("x");
	else
		printf("-");

		
	return 0;
}
