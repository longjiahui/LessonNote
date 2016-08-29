
#include <stdio.h>

void led_init()
{
	printf("%s\n", __func__);
}

void lcd_init()
{
	printf("%s\n", __func__);
}

void i2c_init()
{
	printf("%s\n", __func__);
}

void spi_init()
{
	printf("%s\n", __func__);
}

typedef void (*init_handler)(void);

init_handler funcs[] = {led_init, lcd_init, i2c_init, spi_init};

int main(void)
{
	int i;

	for (i = 0; i < sizeof(funcs)/sizeof(funcs[0]); i++)
		funcs[i]();

	return 0;
}
