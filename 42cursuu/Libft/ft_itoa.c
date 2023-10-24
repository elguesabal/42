

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int	i, copy1, copy2, num;
	char	*str, sign;

	sign = 0;
	i = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
		i++;
	}
	copy1 = n;
	copy2 = n;
	while (n)
	{
		n = n / 10;
		i++;
	}
	str = malloc((i + sign + 1) * sizeof(char));
	if (str)
	{
		str[i] = '\0';
		while (i)
		{
			i--;
			copy1 = copy1 / 10;
			num = copy2 - copy1 * 10;
			copy2 = copy2 / 10;
			str[i] = 48 + num;
		}
		if (str[0] == '0')
		{
			str[0] = '-';
		}
	}
	return (str);
}

int	main(void)
{
	printf("return: %s", ft_itoa(-52304));
	return (0);
}