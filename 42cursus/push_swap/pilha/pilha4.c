#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int items;
    Stack *next;
} Stack;

// Função para inicializar a pilha
void initialize(Stack *stack) {
    stack->top = -1;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Função para verificar se a pilha está cheia
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Função para empilhar um elemento
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Erro: a pilha está cheia\n");
    } else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

// Função para desempilhar um elemento
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Erro: a pilha está vazia\n");
        return -1; // Valor de erro
    } else {
        int poppedItem = stack->items[stack->top];
        stack->top--;
        return poppedItem;
    }
}

// Função para obter o elemento no topo da pilha sem removê-lo
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Erro: a pilha está vazia\n");
        return -1; // Valor de erro
    } else {
        return stack->items[stack->top];
    }
}

int main() {
    Stack minhaPilha;
    initialize(&minhaPilha);

    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);

    printf("Topo da pilha: %d\n", peek(&minhaPilha));

    printf("Elemento desempilhado: %d\n", pop(&minhaPilha));
    printf("Topo da pilha após desempilhar: %d\n", peek(&minhaPilha));

    return 0;
}
