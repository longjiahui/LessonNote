
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 5

typedef int (*compare_t)(const void *arg1, const void *arg2);

int compare(const void *arg1, const void *arg2);
void myqsort(void *arr, int num, int size, compare_t compare);

typedef struct {
	int id;
	char name[20];
	int age;
}student_t;

int main(void)
{
	student_t stus[LEN];
	int i;

	for (i = 0; i < LEN; i++)
	{
		printf("input id name age:");
		scanf("%d %s %d", &stus[i].id, stus[i].name, &stus[i].age);
	}

	myqsort(stus, LEN, sizeof(stus[0]), compare);

	for (i = 0; i < LEN; i++)
		printf("%d  %s  %d \n", stus[i].id, stus[i].name, stus[i].age);
	
	return 0;
}

int compare(const void *arg1, const void *arg2)
{
	student_t *stu1 = (student_t *)arg1;
	student_t *stu2 = (student_t *)arg2;

	return stu1->age - stu2->age;
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
