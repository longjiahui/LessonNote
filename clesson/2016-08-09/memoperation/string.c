
#include <stdio.h>
#include <string.h>

int main(void)
{

	char Buffer[20] = "abcdefghijkl" ; 

	//strcpy(Buffer+3 , Buffer);  //缓存字节数是不固定的
	
	//memcpy(Buffer+3 , Buffer , 11); //没有缓存,直接覆盖
	//memmove(Buffer+3 , Buffer , 11); //全缓存

	printf("Buffer:%s \n" , Buffer);
	
	return 0 ; 
}
