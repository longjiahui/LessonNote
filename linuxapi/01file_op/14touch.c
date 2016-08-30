
#include <stdio.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	char ch;
	int fd;
	
	if (argc < 2)
	{
		printf("usage: ./a.out  file_name \n");
		return 1;
	}

	fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0644);
	if (fd > 0) //表示文件不存在，已创建出来
	{
		close(fd);
	}	
	else //表示文件已存在，改修改时间
	{
		printf("change time\n");
		close(fd);
		fd = open(argv[1], O_WRONLY, 0666);
		read(fd, &ch, 1);
		
		lseek(fd, 0, SEEK_SET);
		write(fd, &ch, 1);	
		close(fd);
	}

	return 0;
}
