
#include <stdio.h>
#include <pthread.h>

void *do_thread(void *arg);

int main(void)
{	
	//gcc thread.c  -lpthread
	//gcc thread.c  -lrt
	//加线程的编译库

	pthread_t tid ; 

	//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                      void *(*start_routine) (void *), void *arg);

	pthread_create(&tid , NULL , do_thread , (void *)88);

	while(1)
	{
		printf("hello world \n");
		sleep(1);
	}

	return 0 ; 
}
//线程沟通可用全局变量

void *do_thread(void *arg)
{
	while(1)
	{
		printf("hello kitty arg:%d \n" , (int)arg);
		sleep(2);
	}
}
