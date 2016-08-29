#include<stdio.h>

int main(void)
{
	int a = 4;
	int b = 5;
	int c = 6;
	int d = 7;
	int tmp ;
	int i ,j;

	for(i = 1;i<=4; ++i)
	{
		for(j = 1;j<=3;++j)
		{
			printf("%d%d%d%d ",a,b,c,d);
			tmp = c;
			c = d;
			d = tmp;
			printf("%d%d%d%d ",a,b,c,d);
			tmp = b;
			b = c;
			c = tmp;
		}
	//printf("\n %d%d%d%d\n",a,b,c,d);
	
	tmp = a;
	a = b;
	b = tmp;
	tmp = b;
	b = c;
	c = tmp;
	tmp = c;
	c = d;
	d = tmp;

	}
	//printf("coun:%d \n",count);	



	return 0;
}
