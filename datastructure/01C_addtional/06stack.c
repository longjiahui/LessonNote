
#include <stdio.h>

#define LEN 8*1024*1024

void func2()
{
	char data[1024];

	func3();
}

void func3()
{
	char data[1024];

	void func4();
}

void func4()
{

}

int main(void)
{
	char data[LEN];		

	data[LEN-1] = '3';

	printf("%c\n", data[LEN-1]);		
	return 0;
}


