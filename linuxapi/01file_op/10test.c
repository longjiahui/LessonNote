
#include <stdio.h>
#include <fcntl.h>

#define LEN (1024*1024*10)

int main(void)
{
	char ch = 'A';
	int fd, i;

#if 1
	fd = open("./test.txt", O_WRONLY|O_CREAT|O_TRUNC,0666);
	for (i = 0; i < LEN; i++)
		write(fd, &ch, 1);
	close(fd);
#endif

#if 0
	FILE *fl;
	fl = fopen("./test.txt", "w+");
	for (i = 0; i < LEN; i++)
		fwrite(&ch, 1, 1, fl);
	fclose(fl);	
#endif


	return 0;
}
