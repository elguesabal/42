#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int my_putchar(char c) {
    return write(1, &c, 1);
}

int main() {
    printf("\nreturn: %d");
    return 0;
}