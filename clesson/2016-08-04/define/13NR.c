
#include <stdio.h>
#include <myhead.h>

#define  NR(x)   (sizeof(x)/sizeof(x[0]))

//int array[-1];  int array[0];
#define BUILD_BUG_ON_ZERO(e) (sizeof(struct { int:-!!(e); }))
#define BUILD_BUG_ON_NULL(e) ((void *)sizeof(struct { int:-!!(e); }))

#define __must_be_array(a) \
	BUILD_BUG_ON_ZERO(__builtin_types_compatible_p(typeof(a), typeof(&a[0])))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))


int main(void)
{
	int array[] = {1,2,3,4,5,6,7,8,9,10};


	printf("size:%d \n" , NR(array));
	printf("size:%d \n" , ARRAY_SIZE(array));

	int *p = NULL ; 

	//printf("size:%d \n" , NR(p));
//	printf("size:%d \n" , ARRAY_SIZE(p));



	return 0 ;
}

