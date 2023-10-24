

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

// int	main(void)
// {
// 	int fd;

//     fd = open("texte.txt", O_WRONLY | O_APPEND | O_CREAT, 0744);
// 	ft_putstr_fd("ft_putstr_fd", fd);
// 	close(fd);
// 	return (0);
// }