
#ifndef  _MYHEAD_H
#define  _MYHEAD_H

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
				

#define BUILD_BUG_ON_ZERO(e) (sizeof(struct { int:-!!(e); }))
#define BUILD_BUG_ON_NULL(e) ((void *)sizeof(struct { int:-!!(e); }))

#define __must_be_array(a) \
	BUILD_BUG_ON_ZERO(__builtin_types_compatible_p(typeof(a), typeof(&a[0])))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))


#endif //_MYHEAD_H
