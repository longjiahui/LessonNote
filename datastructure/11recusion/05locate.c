
#include <stdio.h>

#define ARRAY_SIZE(arr)  (sizeof(arr)/sizeof(arr[0]))

int main(void)
{
	int num[10] = {5, 9,  11, 24, 44, 49, 56, 77, 83, 93};
	int l = 0, r = ARRAY_SIZE(num)-1;

	int a = 8; //要找的数
	
	while (l <= r)
	{
		printf("AAA: l = %d, r = %d, %d\n", l, r, (l+r)/2);
		getchar();

		if (a > num[(l+r)/2])
			l = (l+r)/2+1;

		if (a < num[(l+r)/2])
			r = (l+r)/2-1;
		
		if (num[(l+r)/2] == a)
		{
			printf("found\n");
			break;
		}

		printf("BBB: l = %d, r = %d, %d\n", l, r, (l+r)/2);
		getchar();
	}
		
	

	
	return 0;
}
