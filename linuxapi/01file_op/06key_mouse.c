

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <linux/input.h>

//实现用键盘代替鼠标
//鼠标的设备文件: /dev/input/event3

int main(int argc, char *argv[])
{
	int fd, ret;
	struct input_event evt;
	memset(&evt, 0, sizeof(evt));

	fd = open("/dev/input/event3", O_WRONLY);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}

	char ch;
		
	system("stty -echo -icanon");	
	while (1)
	{
		ch = getchar();
		if (ch == '\033')  // : \033 [ A
		{
			evt.type = EV_REL;
			ch = getchar();
			if (ch != '[')
				continue;
			ch = getchar();
			switch (ch)
			{
			case 'A':
				evt.code = 1;
				evt.value = -2;
//				printf("up\n");
				break;
			case 'B':
				evt.code = 1;
				evt.value = 2;
//				printf("down\n");
				break;

			case 'C':
				evt.code = 0;
				evt.value = -2;
//				printf("right\n");
				break;

			case 'D':
				evt.code = 0;
				evt.value = 2;
//				printf("left\n");
				break;
			}

			write(fd, &evt, sizeof(evt));

			//submit sync 
			memset(&evt, 0, sizeof(evt));
			evt.type = EV_SYN;
			write(fd, &evt, sizeof(evt));
		}

		if (ch == 'Q')
			break;
	}
	system("stty echo icanon");
	return 0;
}

