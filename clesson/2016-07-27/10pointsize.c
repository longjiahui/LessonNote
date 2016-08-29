
#include <stdio.h>

int main(void)
{
	//指针的大小跟类型没有关系   64/8   32/4
	
	//void a ;  //错误

	void *v ;   //万能型指针
	char *ch ; 
	int  *i ; 
	
	printf("void:%d char:%d  int:%d \n" , sizeof(v) , sizeof(ch) , sizeof(i));

	return 0 ; 
}
