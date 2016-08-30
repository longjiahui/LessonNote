
#include <stdio.h>
#include <fcntl.h>


int main(void)
{
	int fd;


	fd = open("./debug.txt", O_WRONLY|O_CREAT, 0644);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}

	dup2(fd, 1); //让fd成为标准输出


	printf("hello ....\n");
	printf("hello ....\n");
	printf("hello ....\n");


	close(fd);
	return 0;
}
