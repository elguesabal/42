

#include "libftprintf.h"

unsigned int	ft_printu(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_printu(n / 10);
		i += ft_printu(n % 10);
	}
	else
	{
		i += ft_printc(n + 48);
	}
	return (i);
}
