
#include <stdio.h>

void A()
{
	printf("in %s\n", __func__);	
}

void B()
{
	A();
	printf("in %s\n", __func__);	
}

void C()
{
	B();
	printf("in %s\n", __func__);	
}



int main(void)
{
	C();
	return 0;
}
