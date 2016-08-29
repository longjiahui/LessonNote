
#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>

//linux下输入设备的设备文件在/dev/input/event*
// 通过 cat /proc/bus/input/devices 查看硬件对应的设备文件

// hexdump /dev/input/event2

int main(void)
{
// linux输入设备驱动交给应用程序的数据是一个结构体struct input_event;

	int fd, ret;
	struct input_event evt;

	fd = open("/dev/input/event2", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}	

	while (1)
	{
		ret = read(fd, &evt, sizeof(evt));
		if (ret <= 0)
			break;
		printf("type = %d, code = %d, value = %d\n", evt.type, evt.code, evt.value);	


	}
	return 0;
}
