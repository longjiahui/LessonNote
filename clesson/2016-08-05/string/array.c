
#include <stdio.h>

#define  NR(x)     (sizeof(x)/sizeof(x[0]))

int main(void)
{

	int array[5] = {1,2,3,4,5};
	int array1[] = {1,2,3,4,5};

	//偏
	int count ; 

	scanf("%d" , &count);

	//跟编译器有一定的关系
	//危险   //可变大小的数组不可以初始化   //int tmp[count] = {0};  //xx
	int tmp[count]={0};   //申请空间从栈来

	printf("size:%d  \n" , NR(tmp));

	return 0 ; 
}
