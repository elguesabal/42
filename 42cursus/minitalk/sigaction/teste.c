#include <stdio.h>
#include <signal.h>

void mySignalHandler(int signum) {
    printf("Sinal %d recebido.\n", signum);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = mySignalHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Erro ao configurar o manipulador de sinal");
        return 1;
    }

    printf("Aguardando sinal SIGINT. Pressione Ctrl+C para enviar.\n");

    while (1) {
        // Aguardar o sinal
    }

    return 0;
}
