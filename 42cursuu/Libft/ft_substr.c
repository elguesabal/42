

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
			*str++ = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
		}
	return (str);
}

int	main(void)
{
	char *str;

	str = ft_substr("teste", 2, 5);
	printf("\nstr: %s", str);
	return (0);
}