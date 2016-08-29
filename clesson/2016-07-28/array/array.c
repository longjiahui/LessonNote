
#include <stdio.h>

#define  NR(x)    (sizeof(x)/sizeof(x[0]))

int main(void)
{
	//相同元素类型的集合体,地址是连续,有自动计数功能,编译器不会检查越界
	//两个属性1.数组  2.指针

	//int array[10] = {1,2,3,4,5,6,7,8,9,10};
	//下标从0开始,0指的是第一个元素
	//int array[10] = {1,2,3};  //如果数据中有元素被初始化,其它未初始化的元素默认为0
	//如果数组没有一个元素被初始化过,则元素值为随机
	//int array[10] ;
	//int array[10] = {0} ;  //定义时初始化
	//array[0]=55 ;   //对数组赋值
	
	//按照下标的方法赋值
	int array[10] = {1,2,[5]=55};

	//遍历
	int i ; 
	for(i = 0 ; i < NR(array) ; i++)
	{
		printf("array[%d]:%d \n" , i , array[i]);
	}


	return 0 ; 
}
