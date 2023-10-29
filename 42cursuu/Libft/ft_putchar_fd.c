/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:12:37 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/27 09:12:39 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h>

// int main(void)
// {
// 	int fd, i;
// 	char str[] = "teste";

// 	fd = open("texte.txt", O_WRONLY | O_APPEND | O_CREAT, 0744);
// 	i = 0;
// 	while (str[i])
// 	{
// 		ft_putchar_fd(str[i] , fd);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }