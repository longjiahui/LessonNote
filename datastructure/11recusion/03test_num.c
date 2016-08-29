
#include <stdio.h>


void func(int num);

int main(void)
{
	func(77889394);  // '7''7'...'4'

}

void func(int num)
{
	if (num <= 0)
		return;
	
	func(num/10);
	printf("num = %d\n", num);
	getchar();
	putchar('0'+num%10);	
}
