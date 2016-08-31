
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	int ret;

	ret = fork();
	if (ret == 0)
	{
		printf("child : pid = %d, ppid = %d\n", getpid(), getppid());	
		sleep(5);
		printf("child : pid = %d, ppid = %d\n", getpid(), getppid());	
		return 0;
	}		

	printf("parent : pid = %d, ppid = %d\n", getpid(), getppid());	
	return 0;
}
