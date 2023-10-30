/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:13:31 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/27 09:13:33 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int fd;

// 	fd = open("texte.txt", O_WRONLY | O_APPEND | O_CREAT, 0744);
// 	ft_putstr_fd("ft_putstr_fd", fd);
// 	close(fd);
// 	return (0);
// }