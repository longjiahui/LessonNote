
#include <stdio.h>
#include <fcntl.h>


int main(void)
{
	int fd;

	umask(0);

	fd = open("./kk.txt", O_WRONLY|O_CREAT, 0777);
	close(fd);

	return 0;
}
