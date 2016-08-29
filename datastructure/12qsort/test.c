
#include <stdio.h>


int main(void)
{
	int nums[2] = {11, 22};
	void *p = nums;

	printf("p + 1= %p\n", p+1);
	printf("p = %p\n", p);
	


	return 0;
}
