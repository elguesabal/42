#include <stdio.h>

int	ft_isalpha(int c)
{
	if (c > 64 && c < 91)
	{
		return (1);
	}
	if (c > 96 && c < 123)
	{
		return (2);
	}
	return (0);
}

int	main(void)
{
	printf("c1: %d", ft_isalpha("*=-"));
	printf("\nc2: %d\n", ft_isalpha('A'));
	printf("c3: %d\n", ft_isalpha('a'));
	return (0);
}
