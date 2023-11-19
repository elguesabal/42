#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// static void move_and_remove(char *destination, char *source, size_t count)
// {
// 	size_t	len;
// 	size_t	i;
// 	size_t	rest;

// 	if (!destination || !source)
// 		return;
// 	len = 0;
// 	while (source[len])
// 		len++;
// 	if (count > len)
// 		return;
// 	i = 0;
// 	while (i < count)
// 	{
// 		destination[i] = source[i];
// 		i++;
// 	}
// 	destination[count] = '\0';
// 	rest = 0;
// 	while (source[rest + count] != '\0')
// 	{
// 		if (source[rest + count] == '\0')
// 			return;
// 		rest++;
// 	}
// 	i = 0;
// 	while (i <= rest)
// 	{
// 		source[i] = source[i + count];
// 		i++;
// 	}
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// size_t	search(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] && str[i] != 'a')
// 	{
// 		i++;
// 	}
// 	if (!str[i])
// 		return (0);
// 	i++;
// 	return (i);
// }

// int main() {
// 	char s1[10] = "testea", s2[10];
// 	printf("antes: %d %d", ft_strlen(s1), ft_strlen(s2));
// 	move_and_remove(s2, s1, search(s1));
// 	printf("\n\ndepois: %d %d", ft_strlen(s1), ft_strlen(s2));
// 	printf("\ndepois: %s %s", s2, s1);
// }


int main() {
	int fd, n;
	char *str;

	fd = open("arquivo.txt", O_RDONLY);
	str = malloc(100 * sizeof(char));
	
	n = read(fd, str, 11);
	str[n] = '\0';
	printf("%s %d\n", str, n);

	n = read(fd, str, 11);
	str[n] = '\0';
	printf("\n%s %d\n", str, n);

	n = read(fd, str, 11);
	str[n] = '\0';
	printf("\n%s %d\n", str, n);

	n = read(fd, str, 11);
	str[n] = '\0';
	printf("\nultimo teste:%s%d", str, n);
	
	close(fd);
}