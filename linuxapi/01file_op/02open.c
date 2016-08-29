
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	fd = open("./my.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}	

	printf("fd = %d\n", fd);	
	
	char ch;

	while (read(fd, &ch, 1) > 0)
		printf("ch = %c\n", ch);

	close(fd);
	return 0;
}
