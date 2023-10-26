

// #include <stdio.h>
#include <stdlib.h>

static char upper(unsigned int i, char c) {
	if (c >= 'a' && c <= 'z')
	{
		return c - 32;
	}
	return c;
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int	i;
	char	*str;

	i = 0;
	while (s[i])
	{
		i++;
	}
	str = malloc((i + 1) * sizeof(char));
	if (str)
	{
		str[i] = '\0';
		while (i)
		{
			i--;
			str[i] = f(i, s[i]);
		}
	}
	return (str);
}

// int	main(void)
// {
// 	printf("%s", ft_strmapi("teste", upper));
// 	return (0);
// }