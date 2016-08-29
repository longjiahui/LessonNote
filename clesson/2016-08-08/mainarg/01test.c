
#include <stdio.h>

//int main(void)   //无参数
//int main(int argc , char *argv[])
int main(int argc , char **argv)
{//argc   shell传参给C语言程序   传参的参数个数   默认情况下执行程序为1

	printf("argc:%d  \n" , argc);

	int i ;
	
	for(i = 0 ; i < argc ;  i++)
	{
		printf("argv[%d]:%s \n" , i ,  argv[i]);
	}

	return 0 ;    //echo $?
}
