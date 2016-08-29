
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char name[10];
}student_t;

#define COUNT  5

int compare(const void *arg1, const void *arg2);
int main(void)
{
	student_t *stus;
	int i;

	stus = malloc(sizeof(student_t)*COUNT);
// stus[COUNT]

	for (i = 0; i < COUNT; i++)
	{
		printf("input id name: ");
		scanf("%d %s", &stus[i].id, stus[i].name);
	}
	
	qsort(stus, COUNT, sizeof(stus[0]), compare);

	
	for (i = 0; i < COUNT; i++)
		printf("stu[%d]: id = %d, name = %s\n", i, stus[i].id, stus[i].name);



	return 0;
}

int compare(const void *arg1, const void *arg2)
{
	student_t *stu1 = (student_t *)arg1;
	student_t *stu2 = (student_t *)arg2;

//	return stu1->id - stu2->id;
	return strcmp(stu1->name, stu2->name);
}
