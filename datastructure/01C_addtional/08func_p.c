
#include <stdio.h>


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

//void (*myfunc[])(char *) = {func0, func1, func2};

typedef void (*myhandler_t)(char *); //这里是定义一个函数指针变量的类型(myhandler_t)
myhandler_t myfunc[] = {func0, func1, func2};


int main(void)
{
	int num;
	

	while (1)
	{
		printf("select func: ");
		scanf("%d", &num);
		myfunc[num]("hello");
	}
	return 0;
}



