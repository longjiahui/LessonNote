
#include <stdio.h>
//数组在函数下的传参

//void func1(int array[10]);
//void func1(int *array);
//void func1(int array[]);
void func1(int (*barray)[10]);

int main(void)
{
	int array[10] = {1,4,7,6,5,3,2,9,8,10};
	//指向有10个成员成员类型为int的数组指针
	//int (*barray)[10] = &array ;   //好理解
	int (*barray)[10] = array ;  //int array[10] => int (*barray)[10] ;


	//func1(array);
	func1(&array);

	int i ;
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%d \n" , (*barray)[i]);
	}

	return 0 ; 
}

//数组在传参时会直接转成指针
//void func1(int array[10])
//void func1(int *array);
void func1(int (*barray)[10])
{
	int i ; 
	for(i = 0 ;i < 10 ; i++)
	{
		printf("array[%d]:%d \n" , i , (*barray)[i]);
	}
}

