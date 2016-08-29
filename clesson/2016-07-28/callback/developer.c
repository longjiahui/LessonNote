

#include "developer.h"  //gf 可以过去头文件

//BOSS_SAY    回调函数
void Start_Meeting(void (*BOSS_SAY)(void))
{
	printf("A lot of things is Done ...  \n");
	
	BOSS_SAY();

	printf("Meeting is Over ... \n");
}
