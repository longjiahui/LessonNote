
#include <stdio.h>

struct node {
	int data;
	
	struct node *left;
	struct node *right;
};
void show_tree(struct node *head);
int main(void)
{
	struct node a, b, c, d ,e, f, h;

	a.data = 44;
	a.left = &b;
	a.right = &c;
	
	b.data = 18;
	b.left = &f;
	b.right = &d;
	
	c.data = 56;
	c.left = NULL;
	c.right = NULL;

	d.data = 32;
	d.left = &e;
	d.right = &h;

	e.data = 29;
	e.left = NULL;
	e.right = NULL;	

	f.data = 16;
	f.left = NULL;
	f.right = NULL;

	h.data = 36;
	h.left = NULL;
	h.right = NULL;

	show_tree(&a);

	return 0;
}

void show_tree(struct node *head)
{
	if (NULL == head)
		return;
	show_tree(head->left);
	show_tree(head->right);
	printf("%02d ", head->data);
}
