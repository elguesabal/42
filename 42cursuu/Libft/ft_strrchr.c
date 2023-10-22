

#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
    const char *result;

    while (*str) {
        if (*str == c) {
            result = str;
        }
        str++;
    }
    return ((char *)result);
}

int	main(void)
{
	char	str[] = "teste", c = 't';

	printf("return: %s\n\n", ft_strrchr(str, c));
	return (0);
}