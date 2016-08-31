
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	execl("./mytest", "hello", "ssss", NULL);
	printf("after execl\n");	
	return 0;
}
