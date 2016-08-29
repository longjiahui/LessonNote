
#include <stdio.h>

struct mylist {
	int data;

	struct mylist *p;
};

int main(void)
{
	struct mylist a, b, c;

	a.data = 11;
	a.p = &b;
	
	b.data = 22;
	b.p = &c;

	c.data = 33;
	c.p = NULL;

///  a  -->  b  -->  c
/////////////////////////////
	struct mylist *p = &a;

	printf("%d\n", p->data);
	p = p->p; // p =  a.p;
	
	printf("%d\n", p->data);
	p = p->p; // p =  b.p;

	printf("%d\n", p->data);

	for (p = &a; p != NULL; p = p->p)
		printf("%d\n", p->data);
	return 0;
}
