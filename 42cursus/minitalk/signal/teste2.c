#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int signum) {
    printf("Recebi o sinal SIGUSR1\n");
    // Faça algo em resposta ao SIGUSR1
}

void sigusr2_handler(int signum) {
    printf("Recebi o sinal SIGUSR2\n");
    // Faça algo em resposta ao SIGUSR2
}

// void teste(int sinal) {
// 	printf("TA FUNFANDO");
// }

int main() {
    // Registrar manipuladores para SIGUSR1 e SIGUSR2
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);
    // signal(SIGINT, teste);

    printf("Meu PID é %d\n", getpid());

    while (1) {
        // Loop infinito para manter o programa em execução
        sleep(1);
    }

    return 0;
}
