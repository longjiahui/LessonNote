
//一秒钟处理一个任务， 用户可不定时提交多个任务。
//未得到处理的任务需要用链表记录起来，处理过的任务从链表里移除掉
//
//实现工作队列

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define TIME  5  //多少秒钟处理一个任务

//定义每个任务的结构体类型
typedef struct mytask {
	int id;   //任务号
	void (*func)(char *); //此任务需调用的函数	
	char args[100];	

	struct mytask *next, *prev;
}mytask_t;

void sig_func(int sig_num);
void func0(char *p);
void func1(char *p);
void func2(char *p);

static mytask_t  head = {.next = &head, .prev = &head}; //链表头节点

int main(void)
{
	mytask_t *task;
	int num;
	void (*funcs[])(char *) = {func0, func1, func2};

	signal(SIGALRM, sig_func);
	alarm(TIME);
	
	while (1)
	{
		//接收用户输入，增加任务
		printf("input task_id  func_num  args: \n");
		task = malloc(sizeof(*task)); 
		scanf("%d %d %s", &task->id, &num, task->args);
		task->func = funcs[num];	

		//加入链表
		task->next = &head;
		task->prev = head.prev;

		head.prev->next = task;
		head.prev = task;

	}
	return 0;
}

//处理一个任务	
void sig_func(int sig_num)
{
	mytask_t *task = head.next;

	if (task == &head)  //没有任务
		goto exit;
	
	//有任务的处理
	printf("task : id = %d ", task->id);
	task->func(task->args);	

	//从链表里移队已处理的节点
	head.next = task->next;
	task->next->prev = &head;

	free(task);
exit:
	alarm(TIME);
}


void func0(char *p)
{
	printf("%s, %s\n", __func__, p);
}

void func1(char *p)
{
	printf("%s, %s\n", __func__, p);
}

void func2(char *p)
{
	printf("%s, %s\n", __func__, p);
}
