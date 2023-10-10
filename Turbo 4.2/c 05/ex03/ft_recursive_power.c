

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if(power < 0)
	{
		return (0);
	}
	else if(nb == 0 && power == 0)
	{
		return (1);
	}
    else if(power == 1)
    {
        return (nb);
    }
	else
	{
        return (ft_recursive_power(nb, power - 1) * nb);
	}
}

int	main(void)
{
	printf("%d", ft_recursive_power(5, 2));
	return (0);
}