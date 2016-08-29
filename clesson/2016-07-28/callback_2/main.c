
#include "developer.h"

int Encrypt(const char *Str , char *Buffer , int len);
int Descrypt(const char *Str , char *Buffer , int len);

int main(void)
{

	//加密
	Do_Encrypt(Encrypt);

	//解密
	Do_Descrypt(Descrypt);

	return 0 ; 
}



int Encrypt(const char *Str , char *Buffer , int len)
{
	int i ; 
	for(i = 0 ; i < len ; i++)
	{
		Buffer[i] = Str[i] + 1 ; 
	}

	Buffer[i] = '\0' ; 

	return 0 ; 
}

int Descrypt(const char *Str , char *Buffer , int len)
{
	int i ; 
	for(i = 0 ; i < len ; i++)
	{
		Buffer[i] = Str[i] - 1 ; 
	}

	Buffer[i] = '\0' ; 

	return 0 ; 
}
