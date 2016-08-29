
#include <stdio.h>

int main(void)
{
	//  int   char   float double  short long 
	//% d/i
/*    //可以注释一块，但是不可以叠加
	int i = 100 ; 
	unsigned int ui = 100 ; 
	char ch = 'A' ;   // 'A'  字符   "abcde"  字符串
	short sh = 65534 ; 
	unsigned short ush = 65535 ; 
	
	printf("i : %i \n" , i);
	printf("i : %u \n" , i);
	printf("ch:%c  \n" , ch);
	printf("float:%f \n" , 33.3);
	printf("double:%lf \n" , 33.33);
	printf("short:%hd \n" , sh);
	printf("unsigned short:%hu \n" , ush);
	//printf("long:%d  longint:%d  \n" , sizeof(long) , sizeof(long int));
	printf("long : %ld \n" , 10000);
	printf("string:%s \n" , "hello world");
	printf("八进制:%o \n" , 255);
	printf("十六进制不带符号:%x \n" , 255);
	printf("十六进制带符号:%p \n" , 255);
*/

	//位宽    数值所占的宽度 默认情况下，没占满的补空格 如果加上0 前面的补空格换成补零
	//默认情况下，数值向右对齐    '-' 数值向左对齐 
	printf("%08d%d\n" , 1000 , 20);
	printf("%7f\n" , 33.333333);  //如果长度超过位宽，则限制解除(没用)

	//位域
	//保留多少位小数点
	printf("%.3f \n" , 33.666666);  //四舍五入  保留小数点后3位
	//如果加上位宽，小数点算1位

	//字符串
	printf("%.5s \n" , "hello world");   //限制字符串的输出长度

	//flag
	printf("%+d \n" , -100);  //'+'    显示正负符号位

	//八进制  十六进制    # 显示进制
	printf("%#o \n" , 255);
	printf("%#x \n" , 255);
	printf("%#d \n" , 255);


	// *   规定位宽
	printf("scure:%*d \n" , 6 , 100);


	return 0 ; 
}
