
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

struct list_head  {
	struct list_head *next, *prev;
};

#define LIST_HEAD(name) \
	struct list_head name = {&name, &name}

void list_add(struct list_head *new, struct list_head *head);
////////////////////

//定义定时器的任务类型
typedef struct {
	int id;   //任务ID
	int interval; //任务执行的间隔时间 10	
	int count;   //用于定时器给此任务计时使用, 每秒钟+1	
		
	struct list_head list;
}mytask_t;


static LIST_HEAD(tasks); //链表头

void sig_func(int sig_num)
{
	struct list_head *tmp;
	mytask_t *task;	
	static long time = 0;

	for (tmp = tasks.next; tmp != &tasks; tmp = tmp->next)
	{
		task = (mytask_t *)((char *)tmp -   (char *)(&((mytask_t *)0)->list));
		task->count++;
		if (task->count == task->interval)
		{
			printf("task : id=%d  time out, now=%ld\n", task->id, time);
			task->count = 0;
		}
	}
	
	alarm(1);
	time++;
}

int main(void)
{
	//当进程收到信号，默认会退出进程。除非处理信号
	signal(SIGALRM, sig_func); //指定此进程收到信号SIGALRM时，触发sig_func函数
	alarm(1); //系统会在3秒钟后，发信号SIGALRM到本进程

	mytask_t *task;
	while (1)
	{
		printf("input id  interval:");
		task = malloc(sizeof(*task));
		scanf("%d %d", &task->id, &task->interval);
		task->count = 0;
		
		list_add(&task->list, &tasks);
	}


	return 0;
}

void list_add(struct list_head *new, struct list_head *head)
{
	new->next = head;
	new->prev = head->prev;
	
	head->prev->next = new;
	head->prev = new;
}
