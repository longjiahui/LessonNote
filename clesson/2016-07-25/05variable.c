
#include <stdio.h>

int main(void)
{
	//变量类型
	//char  int  float   double   long      short  
	//字符  整型 单精度  双精度  长整型    短整型
	// 1     4    4        8       4/8       2
	// 在x64下 long 为 8个字节
	// 在x32下 long 为 4个字节
	
	//变量类型修饰  不会影响类型大小，但是影响类型表示的范围
	//unsigned   signed   static  const  auto  extern  volatile
	//无符号     有符号    静态   常量   自动   外部    不优化
	
	//register
	//寄存器变量

	//查看变量大小 sizeof

	//char ch  ;
	//算术运算符  +  /  *  / %  
	//位操作运算符 << >>  &  |  ~  
	//条件运算符    && ||  !
	//sizeof  运算符  操作符  不是一个函数  内部可放变量类型也可以放变量
	//typeof  获取一个变量的类型  返回一个变量的类型
	//printf("char : %d \n" , sizeof(char));
	//printf("char : %d \n" , sizeof(ch));
	//typeof(ch)  b ; 
	//printf("b : %d \n" , sizeof(b));
	//int a = sizeof(int) ;


	printf("int : %d \n" , sizeof(int));
	printf("float: %d \n" , sizeof(float));
	printf("double: %d \n" , sizeof(double));
	printf("long: %d \n" , sizeof(long));
	printf("short: %d \n" , sizeof(short));


	return 0 ;
}
