
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define LEN 4096

int main(int argc, char *argv[])
{
	int fd_src, fd_dst, ret;
	char *data;

	if (argc < 3)
	{
		printf("usage : ./a.out  src_file   dst_file\n");
		return 1;
	}

	fd_src = open(argv[1], O_RDONLY);
	fd_dst = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);
	
	if ((0 > fd_src) || (0 > fd_dst)) 
	{
		printf("open file failed\n");
		return 2;
	}	

	data = malloc(LEN);

	while (1)
	{
		ret = read(fd_src, data, LEN);
		if (ret <= 0)
			break;
		write(fd_dst, data, ret);
	}
	free(data);

	close(fd_dst);
	close(fd_src);
	return 0;
}
