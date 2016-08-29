
#include <stdio.h>

#if 0
#define  UP    0x01
#define  DOWN  0x02
#define  LEFT  0x03
#define  RIGHT 0x04
#endif

//默认从零开自增
//如果指定起始值,则按照指定的起始值自增

enum 
{
UP   ,
DOWN = 99,
LEFT = 2,
RIGHT
};



int main(void)
{

	printf("UP:%d  DOWN:%d  LEFT:%d  RIGHT:%d  \n" , UP , DOWN , LEFT , RIGHT );


	return 0 ; 
}

