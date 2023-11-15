#include <stdio.h>
#include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int main() {
    // int fd = open("arquivo.txt", O_RDONLY);
    // char str[100];
    // int i = read(fd, str, 100);
    // printf("%d", i);

    char *str = malloc(100 * sizeof(char));
    printf("%s", str);
}