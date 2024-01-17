#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

// Função para inicializar a pilha
void initialize(Stack* stack) {
    stack->top = NULL;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Função para empilhar um elemento
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Função para desempilhar um elemento
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: a pilha está vazia\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = stack->top;
    int poppedItem = temp->data;
    stack->top = temp->next;
    free(temp);

    return poppedItem;
}

// Função para obter o elemento no topo da pilha sem removê-lo
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: a pilha está vazia\n");
        exit(EXIT_FAILURE);
    }

    return stack->top->data;
}

int main() {
    Stack minhaPilha;
    initialize(&minhaPilha);

    push(&minhaPilha, 10);
    printf("%d\n", minhaPilha.top->data);
    push(&minhaPilha, 20);
    printf("%d\n", minhaPilha.top->data);
    push(&minhaPilha, 30);
    printf("%d\n", minhaPilha.top->data);

    // printf("Topo da pilha: %d\n", peek(&minhaPilha));

    // printf("Elemento desempilhado: %d\n", pop(&minhaPilha));
    // printf("Topo da pilha após desempilhar: %d\n", peek(&minhaPilha));

    return 0;
}
