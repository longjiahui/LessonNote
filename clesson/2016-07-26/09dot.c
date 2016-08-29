
#include <stdio.h>

int main(void)
{
	int b ; 
	int a = (1,2,b=200,3,4,5,6,7,8,9);  //最后一个数据为逗号表达式的值
										//其中逗号前面的表达式均会运行

	//中国;
	//无意义 但是正确 不会出现语法错误

	"aaa";
	3;
	12345;
	0;

	printf("a:%d  b:%d \n" , a , b);


	return 0 ; 
}
