#include<stdio.h>
#define NR(x) 	(sizeof(x) /sizeof(x[0]))

void FindRepeaElement(int *a, int sizearray);
int  Find2stBiggestElement(int *a, int sizearray);


int main(void)
{
	int a[]={1,1,2,3,2,5,1,3};
	
	FindRepeaElement(a, NR(a) );
	Find2stBiggestElement(a, NR(a) );

	printf("\n");
	return 0;
}


void FindRepeaElement(int *a, int sizearray)
	{
		int sameelement[10];
		int i,j,k,l = -1;
		for(i = 0; i < sizearray; i++)
		{
			for(j = i + 1; j<  sizearray; j++)
			{
				if(a[ i ] == a [ j ])
				{
					if(l == -1)
					{
						l++;
						sameelement[l] = a[ i ];
					}else
					{
						for(k = 0; k <= l; k++)
							{				
								if(a[i] == sameelement[ k ])
									break;
							}
						if(k == l +1 )
							{
								l++;
								sameelement[l] = a[ i ];
							}
					}
				}
			}
		}
		
		for(i = 0; i<=l; i++)
			printf("%d,",sameelement[i]);
	}


int  Find2stBiggestElement(int *a, int sizearray)
{
	int i,tmp=0;
	
	if( a[ 0 ] < a[ 1 ] )
	{
		tmp =  a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
	
	for(i = 2 ; i < sizearray ; i++)		
	{
		if(a[ i ] > a[ 0 ])
		{
			a[1] = a[0];
			a[0] = a[i];
		}else
		if(a[ i ] <= a[ 2 ])
		{

		}else
		{
			if(a[ i ] > a[ 1 ])
				a[ 1 ] = a[ i ];
		}
	}
	
	printf("The 2st num is %d.\n",a[ 1 ]);
}



