

#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int	i, j, k;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == *set)
		{
			j++;
		}
		i++;
	}
	str = malloc((i - j) * sizeof(char *));
	if (str)
	{
		str[i] = '\0';
		k = i - j;
		do
		{
			i--;
			if (s1[i] != *set)
			{
				k--;
				str[k] = s1[i];
			}
		}
		while (i);
	}
	return (str);
}	// TERMINAR ESSA POHA AKI // ACHO Q TERMINEI MAS TEM Q CONFIRMAR PQ EU TO COM SONO

int	main(void)
{
	printf("return: %s", ft_strtrim("teste", "e")); // PODERIA EXCLUIR MAIS DE 1 CARACTER????
	return (0);
}