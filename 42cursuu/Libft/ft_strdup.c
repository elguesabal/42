

#include <stdio.h>
#include <stdlib.h>

char    *strdup(const char *str)
{
    char    *str2;
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
    str2 = malloc(i * sizeof(char *));
	if (str2)
	{
		str2[i] = '\0';
		do {	// NORMINETTE ACEITA DO WHILE??
			i--;
			str2[i] = str[i];
		} while (i);
	}
    return (str2);
}

int main(void)
{
    char    *str;

    str = strdup("teste");
    printf("str: %s", str);
    return (0);
}