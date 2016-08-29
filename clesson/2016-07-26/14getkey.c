
#include <stdio.h>

int main(void)
{
	
	char ch ; 

	while(1)
	{
		//关闭回显
		system("stty -echo");
		//关闭输入缓冲区
		system("stty -icanon");

		ch = getchar();
		if((ch == '\033') && (getchar() == '[') )
		{
			switch(getchar())
			{
			case 'A' : printf("向上 \n");  break;
			case 'B' : printf("向下 \n");  break;
			case 'C' : printf("向右 \n");  break;
			case 'D' : printf("向左 \n");  break;
			}
		}

		//开启回显
		system("stty echo");
		//开启输入缓冲区
		system("stty icanon");
	}

	return 0 ; 
}
