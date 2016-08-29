
#include <stdio.h>

//  #   字符串转换   将一个非字符串转成字符串

#define   DEBUG(x)  printf("我想说的话是:"x"\n");
#define   DEBUG1(x)  printf("我想说的话是:"#x"\n");

int main(void)
{

	DEBUG("我好饿");
	DEBUG("我一点都不饿");

	DEBUG1(你好);
	DEBUG1(fjdoa123457#&%*$@#$$);

	return 0 ; 
}
