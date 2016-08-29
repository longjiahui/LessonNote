
#include <stdio.h>

#define NR(x)   (sizeof(x)/sizeof(x[0]))

void func(int array[7]);

int main(void)
{

	int array[7] = {1,2,3,4,5,6,7};

	printf("%s size:%d \n" ,__func__ , NR(array));
	printf("%s %p \n" , __func__ , &array);

	func(array);

	return 0 ; 
}

void func(int array[7])
{	//认为是指针
	printf("%s size:%d \n" ,__func__ , NR(array));
	printf("%s %p \n" , __func__ , &array);
	//int brray[7] = {1,2,3,4,5,6,7};
	//printf("brray %s size:%d \n" ,__func__ , NR(brray));
}
