
#include <stdio.h>

int main(void)
{
	//<<  >>  &  |  ~
	//左移 右移  位与  位或  按位取反
	
	//&    1   1 =>  1  只要有个零为零
	//|    只要有个1就为1
#if 0
	unsigned int Num ; 
	Num = 0xFF0F ; 

	printf("Num:%p \n" , Num & 0xF00F);
	printf("Num:%p \n" , Num | 0xF00F);
	printf("Num:%p \n" ,~Num);
#endif

	unsigned int Num ; 

	Num = 0xFF00FF ;   //10  13 14
	//置位  
	//Num |= 0xF << 8;
	//Num |= (1 << 9) | (0x3 << 12) ; 

	//清位
	//Num &=  ~(0xF << 16);   //3  6  26
	//Num &= ~((0x1 << 2)|(0x1 << 5)|(0x1 << 25));
	//取反
	//^  异或   互异为1 相同为0
	//任何值只要当前的位异或于1都会取反
	
	Num ^= (0x1 << 10)|(0x1 << 17); 

	printf("Num:%p \n" , Num);


	return 0 ;
}
