
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

enum
{
LEFT,
RIGHT,
BACKSPACE,
CHAR,
UNKNOWN,
};

int  Offset = 0 ; 
int  Count = 0 ; 
int  Right = 0 ; 
struct timezone tz ;
struct timeval StartTime ; 
struct timeval EndTime ; 

void mycopy(char *Buffer , const char *p , int len);
void show_string(const char *Str , const char *Buf);
int Get_User_Input(char *Buf);

int main(void)
{

	char *Str = "Welcome to Uplooking ... Good Good Study and Day Day UP UP !" ; 
	char Buffer[100] = {0}; 
	
	system("clear");
	while(1)
	{
		show_string(Str, Buffer);

		if(strlen(Str) == Count)
			break;

		Get_User_Input(Buffer);
	}

	putchar('\n');
	putchar('\n');
	putchar('\n');

	return 0 ; 
}



void show_string(const char *Str , const char *Buf)
{
	system("clear");
	
	printf("%s\n" , Str);

	int i ; 
	Right = 0 ; 
	for(i = 0 ; i < Count ; i++)
	{
		if(Str[i] == Buf[i])
		{
			Right++ ; 
			printf("\033[34m%c\033[0m" , Buf[i]);
		}
		else
			printf("\033[31m%c\033[0m" , Buf[i]);
	}

	putchar('\n');
	int sec ; 
	sec = EndTime.tv_sec - StartTime.tv_sec ;
	int usec ; 
	usec = EndTime.tv_usec - StartTime.tv_usec ; 
	int Speed ; 	
	Speed = (60*1000000) / (sec * 1000000 + usec+1) * Right ; 
	
	printf("总个数:%d  已经输入:%d   正确个数:%d  错误个数:%d 速度:%d/min 正确率:%d%% \n" ,strlen(Str),Count , Right , Count-Right ,  Speed  , Right*100 / (Count+1));

	printf("\033[2;%dH" , Offset+1);

	fflush(stdout);
}

static int _Get_User_Input(char *character)
{
	int type ; 
	type = UNKNOWN ; 
	char ch ; 	

	system("stty -echo");
	system("stty -icanon");
	ch = getchar();
	if(ch == '\033' && getchar() == '[')
	{
		switch(getchar())
		{
		case 'C' : type = RIGHT; break;
		case 'D' : type = LEFT; break;
		}
	}else if(ch == 127)
	{
		type = BACKSPACE ; 
	}else
	{
		type = CHAR ; 
		*character = ch ; 
	}
	system("stty echo");
	system("stty icanon");
	return type ; 
}

int Get_User_Input(char *Buf)
{
	int type ; 
	char ch ; 
	type = _Get_User_Input(&ch);
	
	switch(type)
	{
		case LEFT: 
		if(Offset > 0)  Offset -= 1 ; 
		break;
		case RIGHT: 
		if(Offset < Count) Offset += 1 ; 
		break;
		case BACKSPACE : break;
		case CHAR :/*Buf[Count] = ch ;*/ 
		mycopy(Buf+Offset+1 ,Buf+Offset , Count - Offset+1 );	
		//memmove(Buf+Offset+1 , Buf+Offset , Count - Offset);
		Buf[Offset] = ch ; 
		Count++ ; Offset++ ; 
		if(Count == 1)
		{
			gettimeofday(&StartTime , &tz);
		}else
		{
			gettimeofday(&EndTime , &tz);
		}
		 break;
	}

	return 0 ; 
}

void mycopy(char *Buffer , const char *p , int len)
{
	int i ; 
	for(i = len ; i >= 0 ; i--)
	{
		Buffer[i] = p[i];
	}
}


