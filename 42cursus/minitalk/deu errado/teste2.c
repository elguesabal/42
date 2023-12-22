#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    imprimir(unsigned long long p)
{
    printf("%llu\n", p);
}

int main()
{
    char    *teste;
    
    teste = malloc(4 * sizeof(char));
    teste[0] = 'a';
    teste[1] = 'b';
    teste[2] = 'c';
    teste[3] = '\0';

    imprimir((unsigned long long)teste);
    printf("%s\n", teste);

    while (1)
    {
        sleep(5);
    }
}