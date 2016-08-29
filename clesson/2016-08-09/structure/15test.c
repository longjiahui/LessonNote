
#include <stdio.h>


struct t1
{
	long i ; 
	char ch; 
};

struct t2
{
	char ch; 
	struct t1 t ; 
};

int main(void)
{
	printf("size:%d \n" , sizeof(struct t2));

	return 0 ; 
}
