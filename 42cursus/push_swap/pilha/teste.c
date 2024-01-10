#include <stdio.h>

typedef struct {
    int n;
    struct Stack *next;
} Stack;

int main() {

    Stack teste1;
    teste1.n = 10;
    printf("teste1.n: %d\n", teste1.n);

    Stack teste2;
    teste1->next = teste2;
    teste2.n = 20;
    printf("teste2.n: %d\n", teste2.n);


    return 0;
}
