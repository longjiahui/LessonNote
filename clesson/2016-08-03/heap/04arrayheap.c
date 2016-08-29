
#include <stdio.h>
#include <string.h>

//全局区
//全局数组实现数组空间存储在堆区,但是数组指针在全局区,具有全局的特性
char array[1024*1024*1024]  = {0};  //1G
char array1[1024*1024*1024] = {0};  //1G
char array2[1024*1024*1024] = {0};  //1G
char array3[1024*1024*1024] = {0};  //1G

int main(void)
{
	memset(array ,  'A' , 1024*1024*1024);
	memset(array1 , 'A' , 1024*1024*1024);
	memset(array2 , 'A' , 1024*1024*1024);
	memset(array3 , 'A' , 1024*1024*1024);

	printf("sizeof:%d \n" , sizeof(array));
	sleep(10);

	return 0 ;
}

