#include <stdio.h>
#include <stdarg.h>

void    teste(int n, ...) {
    va_list teste;
    va_start(teste, n);


for(int i = 0; i < 10; i++) {
	printf("va_arg: %c\ti: %d\n", va_arg(teste, int), i);
}


    va_end(teste);
}

int main() {
    teste(10, 'a', 'b', 'c');
}