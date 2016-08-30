
#include <stdio.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/resource.h>

int main(void)
{
	struct rlimit  lim;	

	if (getrlimit(RLIMIT_STACK, &lim) < 0)
	{
		perror("get limit failed\n");
		return 1;
	}

	printf("%d, %d\n", lim.rlim_cur, lim.rlim_max);

	return 0;
}


