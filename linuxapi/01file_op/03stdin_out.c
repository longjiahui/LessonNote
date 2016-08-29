
#include <stdio.h>


int main(void)
{
	char data[100];
	int ret;

	ret = read(0, data, sizeof(data));
	data[ret-1] = 0;
//	printf("%s\n", data);
		
	write(1, data, ret);
	return 0;
}
