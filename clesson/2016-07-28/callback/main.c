
#include <stdio.h>
#include "developer.h"

void Say(void);

int main(void)
{
	
	Start_Meeting(Say);


	return 0 ;
}

void Say(void)
{
	printf("hello dog \n");
	printf("hello cat \n");
}


