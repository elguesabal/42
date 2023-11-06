

#include "libftprintf.h"

unsigned int	ft_printx(unsigned int n, const char c)
{
	char hexadecimal[100];
	int rest;
	int i;
	int j;

	if (n == 0)
	{
		return (write(1, "0", 1));
	}
	i = 0;
	while (n > 0)
	{
		rest = n % 16;
		if (rest < 10)
		{
			hexadecimal[i] = rest + '0';
		}
		else
		{
			hexadecimal[i] = rest - 10 + c;
		}
		i++;
		n = n / 16;
	}
	j = i - 1;
	while (j >= 0)
	{
		write(1, &hexadecimal[j], 1);
		j--;
	}
	return (i);
}