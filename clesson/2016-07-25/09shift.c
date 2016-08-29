
#include <stdio.h>

int main(void)
{
	//<<  >>
	//左移
	unsigned int i = 0x1UL ; 
	//0x1UL    U  unsigned  L  long
	//左移右边补零
	printf("sum:%p \n" , 0x1UL << 4);
	
	//unsigned int Num = 0xFFFFFFFF ; 
	int Num = 0x70000000 ; 
	//右移补符号位  如果符号位为0补0  为1 补1
	printf("Num:%p \n" , Num >> 4);


	return 0 ; 
}
