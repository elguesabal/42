#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str && *str > 47 && *str < 58)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}




char* convert_bin(char c) {
    int i;
    char *bin;

    bin = malloc(9 * sizeof(char));
    i = 7;
    while(i >= 0)
    {
        bin[i] = (c & 1) + '0';
        c >>= 1;
        i--;
    }
    bin[8] = '\0';
    return (bin);
}

void	send_signal(int pid, char *bin)
{
	int	i;

	i = 0;
	while(bin[i])
	{
		if(bin[i] == '0')
			kill(pid, SIGUSR1);
		else if(bin[i] == '1')
			kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	pid = ft_atoi(argv[1]);

	i = 0;
	while (argv[2][i])
	{
		ft_strlcpy(char_bin, convert_bin(argv[2][i]), 9);
// printf("%s\n", char_bin);
		send_signal(pid, char_bin);
		i++;
	}
	return (0);
}