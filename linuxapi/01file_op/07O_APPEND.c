
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	fd = open("./abc.txt", O_WRONLY|O_CREAT|O_APPEND, 0644);

	write(fd, "hello\n", 6);

	close(fd);
	return 0;
}
