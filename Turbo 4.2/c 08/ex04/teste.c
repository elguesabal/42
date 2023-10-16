#include <stdio.h>

int main(int argc, char *argv[]) {
    // Verifica se há pelo menos um argumento (o nome do programa)
    if (argc < 2) {
        printf("Uso: %s <argumento>\n", argv[0]);
        return 1;
    }

    // Itera sobre os argumentos e imprime cada um deles usando printf
    for (int i = 1; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }

    return 0;
}

