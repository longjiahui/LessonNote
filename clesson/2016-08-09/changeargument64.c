
#include <stdio.h>

typedef char *vv_list;

#define  _AUPBND                (sizeof (long) - 1)
#define  _ADNBND                (sizeof (long) - 1)

#define _bnd(X, bnd)            (((sizeof (X)) + (bnd)) & (~(bnd)))
#define va_arg(ap, T)  ({								\
						*(T *)(((ap) += (_bnd (T, _AUPBND))) - (_bnd (T,_ADNBND)))})
#define va_end(ap)              (void) 0
#define va_start(ap, A)         (void) ((ap) = (((char *) &(A)) + (_bnd (A,_AUPBND))+20))


void function(int a , ...);

int main(void)
{
	
	
	function(10,20,'A',30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190);
	function(10,20,'A',30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190);

	//前面偏20字节
	//第五个之偏19*8  接下来就连续地址
	//

	return 0 ; 
}

void function(int a , ...)
{
	vv_list  ap ; 

	va_start(ap , a);

	int ret ; 
	
	ret = va_arg(ap , int);
	printf("ret:%d \n" , ret);

	ret = va_arg(ap , int);
	printf("ret:%d \n" , ret);

	ret = va_arg(ap , int);
	printf("ret:%d \n" , ret);

	ret = va_arg(ap , int);
	printf("ret:%d \n" , ret);

	ret = va_arg(ap , int);
	printf("ret:%d \n" , ret);

	int i ; 
	for(i = 0 ; i < 32 ; i++)
	{
		ret = va_arg(ap , int);
		printf("ret:%d i:%d \n" , ret , i);
	//	if(ret == 60)
	//		break;
	}
	va_end(ap);
}

