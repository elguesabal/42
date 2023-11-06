

#include "libftprintf.h"

int	ft_printc(const char c)
{
	return (write(1, &c, 1));
}