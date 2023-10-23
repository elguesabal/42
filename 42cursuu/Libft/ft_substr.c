

#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char    *str;
	int	i;

	str = malloc((len - start) * sizeof(char *));
	if (str)
	{
		i = 0;
		while (start < len)
		{
			*(str + i++) = s[start];
			start++;
		}
		str[i] = '\0';
	}
	return (str);
}

int	main(void)
{
	printf("\nreturn: %s", ft_substr("teste", 2, 5));
	return (0);
}
