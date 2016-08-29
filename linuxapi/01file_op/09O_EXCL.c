
#include <stdio.h>
#include <fcntl.h>


int main(void)
{
	int fd;

	fd = open("./abc.txt", O_WRONLY|O_CREAT|O_EXCL, 0644);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}

		

	close(fd);
	return 0;
}
