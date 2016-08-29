
#include <stdio.h>

int main(void)
{
	int number ;   //变量
	int number1 ; 
	int ret ; 

	//1.
	//默认情况下以空格或者回车键来表示一个输入的结束 ==> 对于整型数据
	//ret = scanf("hello%d,%d" , &number , &number1);
	//格式字符串下有其它字符，则必须按照字符格式照着写
	//如果两个输入数之间有字符，则必须接照字符格式写
	//printf("ret:%d  number:%d  number1:%d \n" , ret , number , number1);
	
	char ch , ch1 ; 
	//2.
	//scanf("%c%c" , &ch , &ch1);  //如果是字符格式必须连着写,不可以加空格或者换行，如果加上则会被吃进去
	//scanf("%c %c" , &ch , &ch1); 
	//printf("ch:%c ch1:%c \n" , ch , ch1);

	//3.
	//如果类型不一致，直接写，会自动分开
	//scanf("%d%c%d" , &number , &ch , &number1);
	//printf("number:%d ch:%c number1:%d \n" , number , ch , number1);
	
	//4.指定输入长度，拿数据只拿到该长度为止
	//scanf("%4d%2d%2d" , &number , &ret , &number1);
	//printf("number:%d ret:%d number1:%d \n" , number , ret , number1);

	//5.抑制符
	//scanf("%4d%*2d%3d" ,&number , &number1 );
	//printf("number:%d  number1:%d  \n" , number , number1);

	return 0 ; 
}
