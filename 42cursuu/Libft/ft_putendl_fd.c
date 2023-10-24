

#include <unistd.h>
#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	int fd;

//     fd = open("texte.txt", O_WRONLY | O_APPEND | O_CREAT, 0744);
// 	ft_putendl_fd("ft_putstr_fd", fd);
// 	close(fd);
// 	return (0);
// }