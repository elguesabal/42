

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int i, result;

	if(power < 0)
	{
		return (0);
	}
	else if(nb == 0 && power == 0)
	{
		return (1);
	}
	else
	{
		result = nb;
		i = 1;
		while(i < power)
		{
			result *= nb;
			i++;
		}
		return (result);
	}
}

int	main(void)
{
	printf("%d", ft_iterative_power(5, 2));
	return (0);
}