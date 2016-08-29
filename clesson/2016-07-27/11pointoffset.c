
#include <stdio.h>

int main(void)
{
	//指针的大小跟类型没有关系   64/8   32/4
	
	//void a ;  //错误

	void *v ;   //万能型指针   //指针未初始化 => 野指针
	char *ch ; 
	int  *i ; 
	double *d ; 
	
	printf("void:%p char:%p int:%p double:%p \n" , v , ch , i , d);
	printf("void:%p char:%p int:%p double:%p \n" , v+1 , ch+1 , i+1 , d+1);
	
	//指针偏移跟指针的类型有关,偏1就偏该对应类型的大小

	return 0 ; 
}
