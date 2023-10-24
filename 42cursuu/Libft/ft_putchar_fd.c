

#include <unistd.h>
#include <fcntl.h>

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

int main(void)
{
    int fd, i;
    char str[] = "teste";

    fd = open("texte.txt", O_WRONLY | O_APPEND | O_CREAT, 0744);
    i = 0;
    while (str[i])
    {
        ft_putchar_fd(str[i] , fd);
        i++;
    }
    close(fd);
    return (0);
}