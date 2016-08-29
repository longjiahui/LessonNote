
#include <stdio.h>

#define LEN 10

int quick_sort(int *num, int l, int r);
int main(void)
{
	int num[LEN];
	int i;

	for (i = 0; i < LEN; i++)
	{
		num[i] = random()%100;
		printf("%02d ", num[i]);
	} 
	printf("\n");
/////////////

	quick_sort(num, 0, LEN-1);		
	
	for (i = 0; i < LEN; i++)
		printf("%02d ", num[i]);
	printf("\n");



	return 0;
}

int quick_sort(int *num, int l, int r)
{
	//快速排序用的左右指针, 用于存放数组操作的元素序号
	int key;
	int l_old = l, r_old = r;
	
	if (l >= r)
		return 0;

	key = num[l];
	while (l  != r)
	{
		while ((num[r] > key) && (l != r))
			r--;
		if (l == r)
			break;

		num[l] = num[r];
		l++;

		while ((num[l] < key) && (l != r))
			l++;	
		if (l == r)
			break;

		num[r] = num[l];
		r--;
	}	
	num[r] = key;
/////
	int i;
	printf("l = %d, r = %d\n", l_old, r_old);
	for (i = 0; i < LEN; i++)
		printf("%02d ", num[i]);
	printf("\n\n");
	getchar();
		
	///////////
	// 0 --- (l-1)
	// (l+1) -- (len-1)
	// 1分二， 二分四， 四分八 ....

	quick_sort(num, l_old, l-1);
	quick_sort(num, r+1, r_old);

	return 0;
}
