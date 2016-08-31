
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>



int copy_file(const char *src, const char *dst);
int copy_dir(const char *src, const char *dst);
int main(int argc, char *argv[])
{
	
	if (argc < 3)
	{
		printf("usage: ./a.out  src  dst ...\n");
		return 1;
	}
	
	if (strcmp(argv[1], argv[2]) == 0)
	{
		printf("src and dst same\n");
		return 2;
	}

	copy_dir(argv[1], argv[2]);	

	return 0;
}

#define LEN_PATH  4*1024
int copy_dir(const char *src, const char *dst)
{
	DIR *dir;
	struct dirent *ent;
	struct stat buf;
	char *path_src = malloc(LEN_PATH);
	char *path_dst = malloc(LEN_PATH);

	dir = opendir(src);
	if (NULL == dir)
		goto exit0;
	
	stat(src, &buf);
	mkdir(dst, buf.st_mode & 0777);

	while ((ent = readdir(dir)) != NULL)
	{
		if (0 == strncmp(".", ent->d_name, 1)) //隐藏的文件和目录不拷贝
			continue;
		
		sprintf(path_src, "%s/%s", src, ent->d_name);
		sprintf(path_dst, "%s/%s", dst, ent->d_name);
		stat(path_src, &buf);
		if (S_ISDIR(buf.st_mode)) //拷贝的是一个目录
			copy_dir(path_src, path_dst);
		else
			copy_file(path_src, path_dst); 
	}

exit0:
	free(path_src);
	free(path_dst);
	return 0;
}

#define LEN  (8*1024)
int copy_file(const char *src, const char *dst)
{
	int fd_dst, fd_src, ret = -1, ret2 = 0;
	struct stat buf;
	char *data = malloc(LEN), *p;

	fd_src = open(src, O_RDONLY);
	if (fd_src < 0)
	{
		perror("open src");
		goto exit0;
	}
	
	fstat(fd_src, &buf);
	fd_dst = open(dst, O_WRONLY|O_CREAT|O_TRUNC, buf.st_mode & 0777);
	if (fd_dst < 0)
	{
		perror("open fd_dst");
		goto exit1;
	}
	
	for (;;)
	{
		ret = read(fd_src, data, LEN);
		if (ret <= 0)
			break;

		for (p = data, ret2 = 0; ret2 < ret; )
		{
			ret2 = write(fd_dst, p, ret-ret2);
			if (ret2 <= 0)
				goto exit2;				
			p += ret2;
			ret = ret - ret2;
			ret2 = 0;
		}
	}
	
	ret = 0;
exit2:	
	close(fd_dst);
exit1:
	close(fd_src);
exit0:
	free(data);
	return ret;	
}
