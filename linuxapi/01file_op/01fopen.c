
#include <stdio.h>

int main(void)
{
	FILE *fl = fopen("./my.txt","w+");
	char buf[] = "hello";	

	fwrite(buf, sizeof(buf), 1, fl);

	fclose(fl);


	return 0;
}
