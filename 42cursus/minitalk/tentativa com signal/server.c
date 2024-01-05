#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *str, size_t size)
{
	char	*str_p;

	str_p = str;
	while (size--)
	{
		*str_p++ = 0;
	}
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	j = len_dst;
	i = 0;
	if (size > 0 && len_dst < size - 1)
	{
		while (len_dst + i < size - 1 && src[i] != '\0')
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		dest[j] = '\0';
	}
	if (len_dst > size)
		len_dst = size;
	return (len_dst + len_src);
}

void putnbr(unsigned int n)
{
	if (n > 9)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

void	putstr(char *str)
{
	write(1, str, ft_strlen(str));
}




char convert_char(const char *bin_str)
{
    int c;
    int i;

	c = 0;
    i = 0;
    while(i < 8)
    {
        if(bin_str[i] == '1')
            c |= (1 << (7 - i));
        i++;
    }
    return ((char)c);
}

void	res(int	signum)
{
	// if(signum == SIGUSR1)
	// 	printf("0\n");
	// else if(signum == SIGUSR2)
	// 	printf("1\n");

	char	c;

	if(signum == SIGUSR1)
		ft_strlcat(char_bin, "0", 8);
	else if(signum == SIGUSR2)
		ft_strlcat(char_bin, "1", 8);

	if(ft_strlen(char_bin) == 8)
	{
		// printf("%c\n", convert_char(char_bin));
		c = convert_char(char_bin);
		write(1, &c, 1);
		ft_bzero(char_bin, 8);
	}
}

int	main(void)
{
	signal(SIGUSR1, res);
	signal(SIGUSR2, res);

	ft_bzero(char_bin, 8);
	putstr("PID: ");
	putnbr(getpid());
	write(1, "\n", 1);
	while(1)
	{
		pause();
	}
	return (0);
}