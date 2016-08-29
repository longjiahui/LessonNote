
#ifndef  _DEVELOPER_H
#define  _DEVELOPER_H

#include <stdio.h>
#include <string.h>

typedef int (*CALLBACK_T)(const char * , char * , int);


//加密
int  Do_Encrypt( CALLBACK_T func );
//解密
int Do_Descrypt( CALLBACK_T  func);


#endif  //_DEVELOPER_H
