
#include <stdio.h>
#include <stdarg.h>

int myprintf(const char *fmt , ...);

int main(void)
{
	myprintf("hello %d %c %f %s %x %o \n" , 123 , 'B',55.2655,"good good",255,255);

	return 0 ; 
}

void  print_num(int num , int base)
{
	if(num == 0)
		return ; 
	print_num(num/base , base);
	putchar("0123456789abcdef"[num%base]);
}

void myputs(const char *str)
{
	while(*str)
	{
		putchar(*str);
		str++ ; 
	}
}

void print_long(long l, int num)
{
	if(l == 0)
		return ; 	
	print_long(l/10 , --num);
	if(num == 0)
		putchar('.');
	putchar("0123456789"[l%10]);
}

void print_float(double db)
{
	long  l ; 
	l = db * 1000000 ;
	print_long(l, 6);
}



int myprintf(const char *fmt , ...)
{
	va_list  ap ; 


	va_start(ap , fmt);

	while(*fmt)
	{
		if(*fmt != '%')
		{
			putchar(*fmt);
			fmt++ ; 
			continue ; 
		}

		//已经找到%
		fmt++ ; 	

		int value ;
		char *str ; 
		double f ; 
		switch(*fmt)
		{
		case 'd' : 
				   value = va_arg(ap , int); 
				   print_num(value , 10);   
				   break;	
		case 'x' : 
				   value = va_arg(ap , int); 
				   print_num(value , 16);   
				   break;	
		case 'o' : 
				   value = va_arg(ap , int); 
				   print_num(value , 8);   
				   break;	
		case 'c' : 
				   value = va_arg(ap , int); 
				   putchar(value);
				   break;	
		case 's' :
				   str = va_arg(ap , char *);
				   myputs(str);
				   break;
		case 'f' : 
				   f = va_arg(ap , double);
				   print_float(f);
				   break;
		}
	
		fmt++ ; 
	}

	va_end(ap);

	return 0 ; 
}



