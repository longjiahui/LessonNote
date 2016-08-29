#include <stdio.h>

int main (void)
{
	int a[]= {1,1,2,3,2,5,1,3};
	int i,j;
	int tmp;
	for(i = 0;i < 7;i++)
	{
		for(j = (i+1);j < 8;j++)
		{
			if(a[i]>a[j])
			{
				tmp = a [i];
				a[i]= a [j];
				a[j]= tmp; 
			}
		}

	} 
	for(i = 0;i<7;i++)
	{	
		tmp = 0;
		for(j = i + 1;j <7;j++)
		{
			if(a[i]!= a[j])
				break;
			i++;
			tmp++;
		}	
		if(tmp != 0)
		printf("%d ",a[i]);
	}

	return 0;
}
