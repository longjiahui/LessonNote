
#include <stdio.h>

#define   NR(x)     (sizeof(x)/sizeof(x[0]))


void Show_Menu(char *Menu[] , int len , int index);

int main(void)
{
	char *Menu[] = {
	"*学生信息添加*",
	"*学生信息删除*",
	"*学生信息打印*",
	"*学生信息保存*",
	"*学生信息导入*",
	"*   退出     *"
	};


	int index = 0 ; 

	while(1)
	{
		Show_Menu(Menu , NR(Menu) , index);
		index++ ; 
		sleep(1);
	}

	return 0 ; 
}

void Show_Menu(char *Menu[] , int len , int index)
{
	int row ; 
	system("clear");
	for(row = 0 ; row < len ; row++)
	{
		if(index == row)
			printf("\033[30m\033[47m\033[%d;30H%s\033[0m" ,5+row , Menu[row]);
		else
			printf("\033[37m\033[40m\033[%d;30H%s\033[0m" ,5+row , Menu[row]);
	}
	fflush(stdout);
}


