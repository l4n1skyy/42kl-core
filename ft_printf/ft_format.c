#include "ft_printf.h"

int ft_ctoa(char c)
{
	write(1, &c, 1);
	return 1;
}

int ft_atoa(char *s)
{
	int len = 0;
	while (*s)
	{
		write(1, s, 1);
		len++;
		s++;
	}
}

int ft_itoa(int)
{
}

int ft_utoa(unsigned int)
{
}

int ft_xtoa(unsigned int)
{
}

int ft_Xtoa(unsigned int)
{
}

int ft_ptoa(void *)
{
}

int ft_percenttoa(void)
{
	write(1, "%", 1);
	return 1;
}
