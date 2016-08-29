
#include <stdio.h>
#include <stdlib.h>
#include <asm-generic/errno-base.h>

//:%s/\*\// /g
//:%s/\/\*/ /g


//错误号所对应的错误信息
#define   ERREPERM	      "Operation not permitted  "
#define   ERRENOENT	      "No such file or directory"  
#define   ERRESRCH	      "No such process          "
#define   ERREINTR	      "Interrupted system call  "
#define   ERREIO	      "I/O error                "
#define   ERRENXIO	      "No such device or address"  
#define   ERRE2BIG	      "Argument list too long   "
#define   ERRENOEXEC      "Exec format error        "
#define   ERREBADF	      "Bad file number          "
#define   ERRECHILD	      "No child processes       "
#define   ERREAGAIN	      "Try again                "
#define   ERRENOMEM	      "Out of memory            "
#define   ERREACCES	      "Permission denied        "
#define   ERREFAULT	      "Bad address              "
#define   ERRENOTBLK      "Block device required    "
#define   ERREBUSY	      "Device or resource busy  "
#define   ERREEXIST	      "File exists              "
#define   ERREXDEV	      "Cross-device link        "
#define   ERRENODEV	      "No such device           "
#define   ERRENOTDIR      "Not a directory          "
#define   ERREISDIR	      "Is a directory           "
#define   ERREINVAL	      "Invalid argument         "
#define   ERRENFILE	      "File table overflow      "
#define   ERREMFILE	      "Too many open files      "
#define   ERRENOTTY	      "Not a typewriter         "
#define   ERRETXTBSY      "Text file busy           "
#define   ERREFBIG	      "File too large           "
#define   ERRENOSPC	      "No space left on device  "
#define   ERRESPIPE	      "Illegal seek             "
#define   ERREROFS	      "Read-only file system    "
#define   ERREMLINK	      "Too many links           "
#define   ERREPIPE	      "Broken pipe              "
#define   ERREDOM	      "Math argument out of domain of func  "
#define   ERRERANGE	      "Math result not representable  "

//五种错误级别
#define   ERRLEV1   "SeriousError : "
#define   ERRLEV2   "Error        : "
#define   ERRLEV3   "Warnning     : "
#define   ERRLEV4   "Signed       : "
#define   ERRLEV5   "Information  : " 

//标准出错
#define   DEBUG1(Errlev,Errmsg,...)	printf("func:%s line:%d \n" , __func__ , __LINE__);\
	fprintf(stderr,"\033[31m"Errlev Errmsg  __VA_ARGS__"\033[0m\n");
#define   DEBUG2(Errlev,Errmsg,...)	printf("func:%s line:%d \n" , __func__ , __LINE__);\
	fprintf(stderr,"\033[31m"Errlev Errmsg  __VA_ARGS__"\033[0m\n");
#define   DEBUG3(Errlev,Errmsg,...)	printf("func:%s line:%d \n" , __func__ , __LINE__);\
	fprintf(stdout,"\033[33m"Errlev Errmsg  __VA_ARGS__"\033[0m\n");
#define   DEBUG4(Errlev,Errmsg,...)	printf("func:%s line:%d \n" , __func__ , __LINE__);\
	fprintf(stdout,"\033[34m"Errlev Errmsg  __VA_ARGS__"\033[0m\n");
#define   DEBUG5(Errlev,Errmsg,...)	printf("func:%s line:%d \n" , __func__ , __LINE__);\
	fprintf(stdout,"\033[34m"Errlev Errmsg  __VA_ARGS__"\033[0m\n");


#define   ERR(errno , condition , errlev , ret , ...)				\
		do															\
		{															\
			if(condition)											\
			{														\
				DEBUG##errlev(ERRLEV##errlev,ERR##errno ,__VA_ARGS__);			\
				ret;												\
			}														\
		}while(0);
				


int main(void)
{
	char *p = NULL ; 
	p = malloc(1024*1024);
	ERR(ENOMEM , NULL == p , 1 , goto e1 , "失败");
	
	char *q = NULL ; 
	q = malloc(1024*1024);
	ERR(ENOMEM , NULL == q , 1 , goto e2 , "失败");
	
	char *o = NULL ; 
	ERR(ENOMEM , NULL == o , 4 , goto e3 , "失败");


//	int a = 100 ; 
//
//	ERR(EAGAIN, a==100, 1 ,           ,"%d %s\n" , a , "这个是一个问题" );
//	ERR(ENOENT, a==100, 1 , return -1 ,"%d %s\n" , a , "我是真的找不到了" );
//
//	printf("number:%d \n" , EAGAIN);


	return 0 ;

e3:
	free(q);
e2:
	free(p);
e1:
	return -ENOMEM ;
}

