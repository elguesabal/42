#include <unistd.h>

int main() {
    // Código ANSI para definir a cor do texto para vermelho
    write(STDOUT_FILENO, "\033[1;31mTexto em Vermelho\033[0m\n", 28);

    // Código ANSI para definir a cor do texto para verde
    write(STDOUT_FILENO, "\033[1;32mTexto em Verde\033[0m\n", 26);

    // Código ANSI para definir a cor do texto para amarelo
    write(STDOUT_FILENO, "\033[1;33mTexto em Amarelo\033[0m\n", 28);

    return 0;
}