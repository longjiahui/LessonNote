
#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	char *p;

	if (argc < 2)
	{
		printf("usage: ./a.out /dir/dir/dir \n");
		return 1;
	}
	// "/aaa/bbb/ccc"

	p = argv[1];

	if (*p == '/')
		p++;

	while (*p)
	{
		while ((*p) && (*p != '/'))
			p++;
		if (0 == *p)
			break;
		// *p == '/'
		*p = 0;
		mkdir(argv[1]);
		*p = '/';

		p++;
	}
	mkdir(argv[1]);

}
