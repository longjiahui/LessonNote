
#include <stdio.h>

void Check_BlackFriday(int year , int sum);

int main(void)
{
	int  year ; 

//	printf("Pls input A Year: \n");
//	scanf("%d" , &year);
//printf("%d 年是%s 年\n" ,year ,((year%4==0)&&(year%100!=0)||(year%400==0))?"闰":"平");

	int sum = 0; 
	for(year=1900 ; year <= 4016 ; year++)
	{
	Check_BlackFriday(year , sum);
	sum+=((year%4==0)&&(year%100!=0)||(year%400==0))?366:365;
	}


	//printf("sum:%d  星期:%d \n" , sum , sum%7);

	return 0 ; 
}
void Check_BlackFriday(int year , int sum)
{
	sum+=13 ; 
	//20160113     sum 
	int month ; 
	int count = 0 ; 
	for(month = 1 ; month <= 12 ; month++)
	{
		if(sum%7 == 5)
		{
			count++ ; 
			printf("year:%d  month:%d is BlackFriday \n" , year , month);
		}
	
		switch(month)
		{
		case 1 : case 3: case 5: case 7: case 8: case 10 :
			sum+=31;  break;
		case 4: case 6: case 9: case 11:
			sum+=30 ; break;
		case 2:
		sum+=((year%4==0)&&(year%100!=0)||(year%400==0))?29:28;
			break;
		}
	}
	if(count == 0)
	{
		printf("**************************\n");
	}
}
