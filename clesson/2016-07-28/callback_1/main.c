
#include <stdio.h>
#include "developer.h"


int add(int a , int b);
int sub(int a , int b);
int mul(int a , int b);
int div(int a , int b);


int main(void)
{

	Do_Calculate(add);
	Do_Calculate(sub);
	Do_Calculate(mul);
	Do_Calculate(div);


	return 0 ; 
}

int add(int a , int b)
{
	return a + b ; 
}
int sub(int a , int b)
{
	return  a - b ; 
}
int mul(int a , int b)
{
	return  a * b ; 
}

int div(int a , int b)
{
	return a / b ; 
}


