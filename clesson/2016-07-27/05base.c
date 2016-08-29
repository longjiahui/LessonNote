
#include <stdio.h>

void function(int num , int base);

int main(void)
{
	int number ; 

	scanf("%d" , &number);

	//十六进制
	function(number , 16);
	putchar('\n');
	//十进制
	function(number , 10);
	putchar('\n');
	//八进制
	function(number , 8);
	putchar('\n');
	//三进制
	function(number , 3);
	putchar('\n');
	//二进制
	function(number , 2);
	putchar('\n');

	return 0 ; 
}
void function(int num , int base)
{
	if(num == 0)
		return ; 
	//过去
	function(num/base , base);
	//char *p = "0123456789ABCDEF" ;
	//p[num%base]  ==>  "0123456789ABCDEF"[num%base]
	putchar("0123456789ABCDEF"[num%base]);
	//回来
}
