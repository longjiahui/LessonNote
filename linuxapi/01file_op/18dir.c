
#include <stdio.h>
#include <dirent.h>

int main(void)
{
	DIR *dir;

	dir = opendir("/var/ftp");
	if (NULL == dir)
	{
		perror("opendir");
		return 1;
	}
/////////////////////////

	struct dirent *ent;
	while (NULL != (ent = readdir(dir)))
	{
		printf("type = %d, name = %s\n", ent->d_type, ent->d_name);
	
	}
		

	closedir(dir);
	return 0;
}
