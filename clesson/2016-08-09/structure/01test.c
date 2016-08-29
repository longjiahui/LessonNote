
#include <stdio.h>
#include <stdlib.h>

//学生结构体的声明    没有空间 不可以赋值
struct Student
{
	int Id  ; 
	float  Score ; 
	int Sex ; 
};


//struct Student  Stt ;  //全局区   未初始化定义
//struct Student  Stt = {22,55.55,0};  //全局区  初始化定义
struct Student  Stt = {
	.Id = 33,
	.Score = 99.99,    //对应成员赋值
	.Sex = 1,
};  //全局区  初始化定义


int main(void)
{
	//定义
	//struct Student Stu ;   //栈区  未初始化定义
	//struct Student Stu = {12,33.33,1} ;   //栈区  初始化定义
	struct Student Stu = {
		.Id = 22,
		.Score=44.44,
		.Sex = 0 ,
	} ;   //栈区  初始化定义
	
	//普通变量类型(非指针),访问成员用.
	//全局区或者静态区,未初始化的结构体会被清零
	printf("id:%d score:%f sex:%d \n" , Stt.Id , Stt.Score , Stt.Sex);
	//栈区未初始化结构体,值随机
	printf("id:%d score:%f sex:%d \n" , Stu.Id , Stu.Score , Stu.Sex);


	struct Student *Stp = NULL ;  //结构体指针   指针属于栈区

	//分配堆空间  堆区
	Stp = malloc(sizeof(struct Student));

	if(NULL == Stp)
	{
		perror("malloc fail");
		return -1 ;
	}

	//赋值  只能做普通赋值
	//对于结构体指针来说,访问成员用->
	Stp->Id = 33;
	Stp->Score = 55.55 ;
	Stp->Sex = 1;

	printf("id:%d score:%f sex:%d \n" , Stp->Id , Stp->Score , Stp->Sex);

	free(Stp);

	return 0 ; 
}
