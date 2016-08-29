
#include <stdio.h>
#include <stdlib.h>
#define LEN 10

int compare(const void *arg1, const void *arg2);
int main(void)
{
// qsort(数组的首地址, 元素个数， 每个元素大小, 比较函数地址)
// qsort地根据比较函数的返回值实现升降序。比较函数的两个参数为要比较的两个元素的地址
//  qsort可支持各种类型的数组

	int num[LEN], i;

	for (i = 0; i < LEN; i++)
	{
		num[i] = random()%100;
		printf("%02d ", num[i]);
	}
	printf("\n");

	qsort(num, LEN, sizeof(num[0]), compare);
	for (i = 0; i < LEN; i++)
		printf("%02d ", num[i]);
	printf("\n");

	return 0;
}

int compare(const void *arg1, const void *arg2)
{
	int a = *(int *)arg1;
	int b = *(int *)arg2;

	return b-a;
}
