
#include <stdio.h>

//函数的声明
void func(void);
void func(void);

//函数声明最重要的是类型,也就是说类型对了就可以
//1.返回值必须一致
//2.函数名字一致
//3.参数个数及参数类型一致
//
//int add(int a , int b); //指针函数   函数的声明
//int add(int c , int d);
//int add(int , int );

//int (*add)(int,int);  //函数指针    函数的定义

extern void haha(void);  
void (*hehe)(void) = haha ;   //相当于函数的定义

typedef void (*func_t)(void);
func_t  ee = haha;   //变量
//func_t == fun_t *
typedef void (fun_t)(void);
fun_t  *pp = haha ; 

int main(void)
{
	int a = 100 ; 
	int b = 200 ; 

	func();
	//add     函数指针
	//add();  函数调用
	printf("sum:%d  \n" , add(a , b));

	//extern void haha(void);  
	//haha();
	hehe();
	ee();
	pp();

	return 0 ; 
}

//函数实现
void func(void)
{
	printf("hello world  \n");
}

int add(int b , int c)
{
	return c + b ; 
}

