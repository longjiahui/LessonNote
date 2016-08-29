
#include <stdio.h>

//define参数
#define    NR(x)       (sizeof(x)/sizeof(x[0]))
#define    ADD(a,b)    ((a)+(b))
#define    msleep(x)   (usleep((x)*1000))


int main(void)
{
	int array[] = {1,2,3,4,5};

	printf("size:%d \n" , NR(array));

	msleep(5000);

	printf("sum:%d \n" , ADD(2+2,2+3));

	return 0 ; 
}
