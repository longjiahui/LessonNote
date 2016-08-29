
#include <stdio.h>

//声明且定义  定义的是一个全局变量
struct Student
{
	int Id ; 
	int Sex ; 
}AA,BB,CC={10,20};

//AA BB  CC的结构体类型是一致的

//这种方式只有在初始化时定义变量,以后再也定义不了变量
//正常指针    struct student *
//这种形态没有指针形式  struct *  错误

//sizeof(AA)  sizeof(struct Student)  两种都有
//sizeof(DD)   只有

struct  
{
	int Id ; 
	int Sex ; 
}DD={44,55} , FF;  //直接结构定义

struct 
{
	int Id ; 
	int Sex ; 
}EE;

int main(void)
{
	printf("id:%d sex:%d \n" , CC.Id , CC.Sex);
	AA=CC ; 
	printf("id:%d sex:%d \n" , AA.Id , AA.Sex);
	printf("id:%d sex:%d \n" , BB.Id , BB.Sex);

	//EE=DD ;  //结构体类型不相同
	FF=DD ; 

	//除非用这种形式才可以定义相同的变量  不正规做法
	typeof(DD)  XX;
	XX=DD ;

	return 0 ; 
}
