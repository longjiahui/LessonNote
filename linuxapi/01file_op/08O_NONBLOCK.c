
#include <stdio.h>
#include <fcntl.h>


int main(void)
{
	char data[100];
	int ret;
	
	//取出文件描述符0的打开状态标志，加上非堵塞的标志
	fcntl(0, F_SETFL, fcntl(0, F_GETFL)|O_NONBLOCK);


while (1)
{
	ret = read(0, data, sizeof(data));
	data[ret-1] = 0;
	printf("got : %s\n", data); 
}	




	return 0;
}
