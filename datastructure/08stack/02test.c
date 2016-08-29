#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//栈： 分配局部变量的空间，存放变量的值。
//     先进后出， 后进先出 
//     出入栈按固定单位大小， 如单位4个字节 , 入栈100这节
//     栈只要有记录栈顶的位置即可, 栈顶是最后一个入栈的位置， 出栈后，栈顶需要变化
//
//     压栈就是把变量的值存放到栈上， 出栈就是从栈上把值取出给变量
// 实现栈的模型


#define LEN  (100*1024*1024)   //栈的空间大小

typedef struct {
	char  *p;  //指定栈的空间首地址
	int size;  //每次出入栈的单位大小

	char *top; //栈顶指针，记录栈顶位置	
}stack_t;

stack_t *create_stack(int size); //创建一个栈出来, size为出入栈的单位大小
void destroy_stack(stack_t *s);

void push_stack(stack_t *s, void *data);
int pop_stack(stack_t *s, void *data);

typedef struct {
	int id;
	char name[20];
}student_t;

int main(void)
{
	stack_t *stack = create_stack(sizeof(student_t)); 
	student_t stu;

	while (1)
	{
		printf("input id  name:");
		scanf("%d %s", &stu.id, stu.name);
		
		if (stu.id < 0)
			break;

		push_stack(stack, &stu);
	}

	while (pop_stack(stack, &stu) == 0)
		printf("id = %d, name = %s\n", stu.id, stu.name);

	

	destroy_stack(stack);
	return 0;
}

int pop_stack(stack_t *s, void *data)
{
	if (s->top == s->p)
	{
		printf("stack empty\n"); // 空栈
		return -1;
	}
	s->top -= s->size;	
	memcpy(data, s->top, s->size);
	return 0;
}

void push_stack(stack_t *s, void *data)
{
	if ((s->top - s->p) >= LEN) //判断是否栈爆
	{
		printf("stack overflow\n");
		return;
	}

	memcpy(s->top, data, s->size);
	s->top += s->size;
}

stack_t *create_stack(int size)
{
	stack_t *t = malloc(sizeof(*t));
	
	t->p = malloc(LEN);
	t->size = size;
	t->top = t->p;
	return t;
}

void destroy_stack(stack_t *s)
{
	free(s->p);
	free(s);
}
