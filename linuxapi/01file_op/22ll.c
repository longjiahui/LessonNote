
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>


void stat_entry(char *path_name);
int main(int argc, char *argv[])
{
	struct stat buf;

	if (argc < 2)
	{
		printf("usage: ./a.out  dir/file");
		return 1;
	}	

	stat(argv[1], &buf);
	if (!S_ISDIR(buf.st_mode))
	{
		stat_entry(argv[1]);
		return 0;
	}
	
	//目录的处理
	DIR *dir;
	struct dirent *ent;	
	char path[500], *p = argv[1];

	dir = opendir(p);
	while (NULL != (ent = readdir(dir)))
	{
		if (p[strlen(p)-1] != '/')
			sprintf(path, "%s/%s", argv[1], ent->d_name);
		else
			sprintf(path, "%s%s", argv[1], ent->d_name);
		stat_entry(path);
	}


	closedir(dir);
	return 0;
}

void stat_entry(char *path_name)
{
	struct stat buf;

	stat(path_name, &buf);

	if ((buf.st_mode & S_IFMT) == S_IFREG)
		putchar('-');
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		putchar('d');
	if ((buf.st_mode & S_IFMT) == S_IFCHR)
		putchar('c');
	if ((buf.st_mode & S_IFMT) == S_IFBLK)
		putchar('b');
	if ((buf.st_mode & S_IFMT) == S_IFLNK)
		putchar('l');
	
	
	if (buf.st_mode & S_IRUSR)
		putchar('r');
	else
		putchar('-');
	
	if (buf.st_mode & S_IWUSR)
		putchar('w');
	else
		putchar('-');
	
	if (buf.st_mode & S_IXUSR)
		putchar('x');
	else
		putchar('-');

		
	printf("\t\t%s\n", path_name);
}
