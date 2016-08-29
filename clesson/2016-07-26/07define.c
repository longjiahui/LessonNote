
#include <stdio.h>

//编译
//1.预处理   1> 展开头文件   2> 展开宏定义     gcc  xxx.c -E  -o xxx.i
//2.编译成汇编  x86架构 CISC complex instruction set Computer  复杂的指令集
//              ARM架构 RISC Reduce instruction set Computer   精简指令集
//              gcc -S  xxx.c  自动生成 xxx.s     //xxx.s  xxx.S
//				gcc -S  xxx.c  -o xxx.S  一样
//3.编译成二进制文件
//gcc -c  xxx.c    自动生成 xxx.o  二进制文件
//gcc -c xxx.c  -o xxx.o
//
//4.链接成为可执行文件 ELF文件
//gcc  xxx.c  -o xxx
//
//5.有了可执行文件，想反编译.反汇编
//objdump -D  07define   >  07define.dump
//
//6.查看可执行程序的函数地址
//nm  07define    可以查看函数地址
//

#define  SIZE  512

void ohmygod(void);

int main(void)
{
	int a = SIZE ; 

	return 0 ; 
}
void ohmygod(void)
{
	int a ; 
	int b ; 
}
