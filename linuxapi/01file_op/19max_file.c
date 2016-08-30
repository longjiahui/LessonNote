
#include <stdio.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/resource.h>

#define LEN  1000000

int main(void)
{
	struct rlimit  lim;	

	if (getrlimit(RLIMIT_NOFILE, &lim) < 0)
	{
		perror("get limit failed\n");
		return 1;
	}

	printf("%d, %d\n", lim.rlim_cur, lim.rlim_max);

	lim.rlim_cur = LEN;
	lim.rlim_max = LEN;

	if (setrlimit(RLIMIT_NOFILE, &lim) < 0)
	{
		perror("set limit failed\n");
		return 1;
	}
///////////////////////////////////

	int i, fd;

	for (i = 0; i < LEN; i++)
	{
		fd = open("./kk.txt", O_RDONLY|O_CREAT, 0644);
		printf("fd = %d\n", fd);
	}



	return 0;
}


