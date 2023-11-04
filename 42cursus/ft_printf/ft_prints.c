

#include "libftprintf.h"

int	ft_prints(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i += ft_printc(str[i]);
	}
	return (i);
}