
#include <stdio.h>
#include <stdlib.h>

struct  human_t {
	int id;
	char name[20];
	int sex;
	int age;
};

int main(void)
{
	struct human_t *p = NULL;

	p = (struct human_t *)0;

	printf("%p\n", p);
	printf("%p\n", &p->id);
	printf("%p\n", &p->name);
	printf("%p\n", &p->sex);
	printf("%p\n", &p->age);



	return 0;
}
