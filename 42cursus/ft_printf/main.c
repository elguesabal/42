#include "libftprintf.h"
#include <stdio.h>

int main() {
    char c;
    int n;

    n = ft_printf("%p\n", &c);
    printf("%d", n);
}