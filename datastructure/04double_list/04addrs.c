
#include <stdio.h>

char *func();
int main(void)
{
	char *p = NULL;

	p = func();

	printf("%s\n", p); 
	return 0;
}

char *func()
{
	char l[] = "hello world"; //字符串"hello world"存放在只读数据段，当这行代码执行时，会把这字符串复制到l数组里
	
	//局部变量都是在栈里分配空间的， 函数执行结束后需要回收这个函数在栈里所分配出来的空间
	
	
	return l;
}
