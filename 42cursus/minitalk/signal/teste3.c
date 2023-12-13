#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// Variável global para armazenar a string recebida


// Função de manipulação de sinal para o processo de destino
void signalHandler(int signum) {
    char receivedString[256] = "";
    int index = 0;
    // Verificar se o caractere recebido é um sinal válido
    if (signum >= SIGRTMIN && signum <= SIGRTMAX) {
        // Extrair o caractere do sinal e concatenar à string
        char receivedChar = (char)(signum - SIGRTMIN);
        receivedString[index++] = receivedChar;
        receivedString[index] = '\0';  // Adicionar o caractere nulo ao final da string

        // Imprimir a string recebida
        printf("String recebida: %s\n", receivedString);
    }
}

int main() {
    // Registrar a função de manipulação de sinal
    signal(SIGRTMIN, signalHandler);

    printf("Aguardando sinais para receber a string... %d\n", getpid());

    // Aguardar um tempo para receber sinais (pode ser substituído por um loop de espera)
    while (1)
        sleep(10);

    return 0;
}
