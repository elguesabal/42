#include <stdio.h>
#include <signal.h>

int i = 0;

void handleSignal(int signum) {
    printf("Recebi o sinal %d\n", i);
    i++;
}

int main() {
    // Registrar handleSignal para tratar o sinal SIGINT (Ctrl+C)
    signal(SIGINT, handleSignal);

    while (1) {
        // Loop infinito
    }

    return 0;
}
