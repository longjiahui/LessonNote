
#include <stdio.h>
#include <sys/time.h>

int main(void)
{
	struct timeval tv;
	struct timezone tz;

	gettimeofday(&tv , &tz);

	printf("sec:%d  usec:%d  \n" , tv.tv_sec , tv.tv_usec);


	return 0 ; 
}
