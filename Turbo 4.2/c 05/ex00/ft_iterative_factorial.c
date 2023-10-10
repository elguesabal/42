

#include <stdio.h>

int	ft_interative_factorial(int nb)
{
	int i, result;

	if(nb == 0 || nb == 1)
	{
		return (1);
	}
	else if(nb < 0)
	{
		return (0);
	}
	else
	{
		result = 1;
		i = 2;
		while(i <= nb)
		{
			result *= i;
			i++;
		}
		return (result);
	}
}

int	main(void)
{
	printf("%d", ft_interative_factorial(5));
	return (0);
}