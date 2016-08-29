
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10

typedef int (*compare_t)(const void *arg1, const void *arg2);

int compare(const void *arg1, const void *arg2);
void myqsort(void *arr, int num, int size, compare_t compare);

int main(void)
{
	int nums[LEN];
	int i;

	for (i = 0; i < LEN; i++)
	{
		nums[i] = random()%100;
		printf("%02d ", nums[i]);
	}
	printf("\n");

	myqsort(nums, LEN, sizeof(nums[0]), compare);

	for (i = 0; i < LEN; i++)
		printf("%02d ", nums[i]);
	printf("\n");
	
	return 0;
}

int compare(const void *arg1, const void *arg2)
{

	return *(int *)arg1  - *(int *)arg2;
}

// arr为数组首地址, size为数组一个元素的大小
void _qsort(void *arr, int size, int l, int r, compare_t compare) //递归调用
{
	int l_old = l, r_old = r;
	void *key = malloc(size); //存放一个元素的数据

	if (l >= r)
		return;
	
	memcpy(key, arr+l*size, size);

	while (l != r)
	{
		while ((l != r) && (compare(arr+r*size, key) >= 0))
			r--;
		if (l == r)
			break;

		memcpy(arr+l*size, arr+r*size, size);
		l++;
		
		while ((l != r) && (compare(key, arr+l*size) >= 0))
			l++;
		if (l == r)
			break;

		memcpy(arr+r*size, arr+l*size, size);
		r--;
	}
	memcpy(arr+l*size, key, size);
	free(key);

	_qsort(arr, size, l_old, l-1, compare);
	_qsort(arr, size, l+1, r_old, compare);
}
void myqsort(void *arr, int num, int size, compare_t compare)
{

	_qsort(arr, size, 0, num-1, compare);
}
