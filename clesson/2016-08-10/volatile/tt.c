
int _start(void)
{
	//嵌入式软件工程师  与  软件工程师  最大区别
	//1.免优化  取消编译器对C语言的优化
	//2.共享型变量一般要加volatile  防竟争
	
	volatile int a = 100 ; 
	a = 1 ; 
	a = 0 ; 
	a = 1 ; 
	a = 0 ; 

	return 0 ; 
}
