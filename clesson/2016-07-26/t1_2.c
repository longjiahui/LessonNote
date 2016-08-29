
#include <stdio.h>

int main(void)
{
	
	int i , j , k , l ; 
   for(i=4;i<8;i++)
   {
       for(j=4;j<8;j++)
           {
               if(j!=i)
                   {
                       k=(22-i-j)/2;
                           if((k!=i)&&(k!=j))
                               {
       printf("%d%d%d%d\n",i,j,k,22-i-j-k);
       printf("%d%d%d%d\n",i,j,22-i-j-k,k);
                               }
                           else
                               {
                                   k--;
       printf("%d%d%d%d\n",i,j,k,22-i-j-k);
       printf("%d%d%d%d\n",i,j,22-i-j-k,k);
                               }
                   }
           }
       }

	return 0 ; 
}
