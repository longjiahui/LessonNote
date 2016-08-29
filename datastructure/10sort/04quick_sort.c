
#include <stdio.h>

#define LEN 10
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
	int l, r; //快速排序用的左右指针, 用于存放数组操作的元素序号
	int key;

	l = 0; //刚开始, 左指针从第0个元素位置开始
	r = LEN-1; //  右指针从最后一个元素的位置开始

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
		

	for (i = 0; i < LEN; i++)
		printf("%02d ", num[i]);
	printf("\n");


	return 0;
}
