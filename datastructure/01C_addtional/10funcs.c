
#include <stdio.h>

void led_init(char *p)
{
	printf("%s, %s\n", __func__, p);
}

void lcd_init(char *p)
{
	printf("%s, %s\n", __func__, p);
}

void i2c_init(char *p)
{
	printf("%s, %s\n", __func__, p);
}

void spi_init(char *p)
{
	printf("%s, %s\n", __func__, p);
}

typedef void (*init_handler)(char *);

struct mycmd_t {
	char *args;
	init_handler handler;
};

struct mycmd_t cmds[] = {
	{"arg1", led_init},	
	{"arg2", lcd_init},
	{"arg3", i2c_init},
	{"arg4", spi_init},
};


int main(void)
{
	int i;

	for (i = 0; i < sizeof(cmds)/sizeof(cmds[0]); i++)
		cmds[i].handler( cmds[i].args );

	return 0;
}
