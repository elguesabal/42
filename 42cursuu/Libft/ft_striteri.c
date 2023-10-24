

#include <stdio.h>

static void upper(unsigned int i, char *str) {	// FUNCAO DE TESTE
	while (*str)
	{
printf("%c\n", *str);
		if (*str >= 'a' && *str <= 'z')
		{
			//*str = *str + 'a' - 'A';
			//*str = *str - 32;
			//*str -= 32;
			//*str = 'w'; // NAO ENTENDI O CORE DUMPED
		}
		str++;
	}
}

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	f(0, s);
	// int	i;

	// i = 0;
	// while (s[i] != '\0')
	// {
	// 	f(i, (s + i));
	// 	i++;
	// }
}

int main(void)
{
    ft_striteri("teste", upper);
    return (0);
}