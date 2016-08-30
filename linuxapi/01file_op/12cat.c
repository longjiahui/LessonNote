
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define LEN (4*1024)

int main(int argc, char *argv[])
{
	int fd, ret;
	char *data;

	if (argc < 2)
	{
		printf("usage: ./a.out file_name");
		return 1;
	}
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}
	
	data = malloc(LEN);

	while (1)
	{
		ret = read(fd, data, LEN);
		if (ret <= 0)
			break;
		data[ret] = 0;
		printf(data);
	}
	close(fd);
	free(data);
	return 0;
}
