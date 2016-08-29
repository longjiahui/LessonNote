
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_func(int sig_num)
{
	printf("signal ...%d\n", sig_num);

	alarm(3);
}

int main(void)
{
	//当进程收到信号，默认会退出进程。除非处理信号

	signal(SIGALRM, sig_func); //指定此进程收到信号SIGALRM时，触发sig_func函数
	
	
	alarm(3); //系统会在3秒钟后，发信号SIGALRM到本进程
	

	while (1)
	;
// 任务1(6秒执行一次),  任务2(9秒一次), 任务3(12秒)
// 共用一个alarm定时器
	return 0;
}
