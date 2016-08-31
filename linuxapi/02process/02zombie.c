
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	int ret;

	ret = fork();
	if (0 == ret) //子进程
	{
		printf("in child: pid = %d, ppid = %d\n", getpid(), getppid());
		return 0;
	}

	//
	printf("in parent: pid = %d, ppid = %d, child = %d\n", getpid(), getppid(), ret);
//	printf("wait : %d\n", wait(NULL));
	sleep(20);
	return 0;
}
