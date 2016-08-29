
#include <stdio.h>

//define  可变参

#define   DEBUG(A,...)    printf("错误:"#A,__VA_ARGS__);

int main(void)
{

	DEBUG(我饿了:%d %c %f \n, 100 , 'A' , 33.33);



	return 0 ;
}
