
#include <stdio.h>

int main(void)
{
	//int  array[3][3] = {1,2,3,4,5,6,7,8,9};  //1.
	//int  array[][3] = {1,2,3,4,5,6,7,8,9}; //2.
	//int  array[3][3] = {{1,},{0},{0,0,9}}; //3.
	//int  array[3][3] = {{1,},{0},{[2]=9}};   //4
	//int  array[3][3] = {1,[2][2]=9};   //5.
	//int  array[3][3] = {1,2,3,{2,3,4},[2][2]=9};   //5. //如果后面有花括号,前面如果没有花括号,那么得补够位数才行
	int  array[3][3] = {{1},{2,3,4},[2][2]=9};   //5.
	//{}{}{}==>[2][2]

	//int array[3][] ; //不行
	
	//int *tmp ;   //每偏移一个,偏移一个整型单元  ==> int tmp[] ; 
	int (*Array)[3]  = array;  //每偏移一个,偏移一个一维数组 ==> int Array[][3] ; 
	//int (*Array)[3][3] = &array ;  //==>Array[][3][3];
	//==> *((*Array+i)+j) ;
	
	//int array[3][3]; ==>  int (*array)[3] ; 
	//array+1

	//int array[3] ; 
	//           i[array] ==> array[i]
	//           array[i] ==> *(array+i)
	
	//遍历
	int i , j ; 

	for(i = 0 ; i < 3 ; i++)
	{
		for(j = 0 ; j < 3 ; j++)
		{
			//printf("%d \n" , array[i][j]);  //1.
			//first
			//printf("%d \n" , i[Array][j]);
			//printf("%d \n" , i[array][j]);  //2.
			//printf("%d \n" , j[i[array]]);  //3.
			//printf("%d \n" , j[array[i]]);    //4.

			//second
			//printf("%d \n" , (*(array+i))[j]);  //5.
			//printf("%d \n" , *((*(array+i))+j));  //6.
			//printf("%d \n" , *(array[i]+j));  //7.
			
			//third
			//利用数组的连续性
			//printf("%d \n" , *((int *)array+3*i+j));  //8.
			//printf("%d \n" , *((int *)array[0]+3*i+j));  //9.
			//printf("%d \n" , *((int *)&(array[0])+3*i+j));  //10.
			//printf("%d \n" , *((int *)(&array[0][0])+3*i+j));  //11.
			//printf("%d \n" , *((int *)(&array)+3*i+j));  //12.
			
			//printf("%d \n" , *((&array[0][0])+3*i+j));  //
			//printf("%d \n" , *(array[0]+3*i+j));  //

			printf("%d \n" , *((char *)array+(3*i+j)*4));  //8.

		
		}
	}

	return 0 ; 
}

