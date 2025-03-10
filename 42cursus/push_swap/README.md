# push_swap

## Sumário

- [Introdução](#introdução)
- [Regras](#regras)
- [Compilação](#compilação)
- [Uso](#uso)
- [Operadores Disponíveis](#operadores-disponíveis)
- [Estrutura do Diretório](#estrutura-do-diretório)

## Introdução

O **push_swap** é um programa que recebe uma lista de números inteiros como argumentos e os ordena utilizando um conjunto limitado de operações em duas pilhas (stack A e stack B). O objetivo é ordenar os números com o menor número possível de operações.

## Regras

- O programa deve utilizar apenas duas pilhas.
- Apenas um conjunto limitado de operações pode ser utilizado para movimentar os elementos entre as pilhas.
- A ordem dos números de entrada deve ser preservada até que o algoritmo os ordene corretamente na pilha A.

## Compilação

Para compilar o programa, utilize:

```sh
make
```

Isso gerará o executável `push_swap`.

## Uso

Para executar o programa, use:

```sh
./push_swap [lista de números inteiros]
```

Exemplo:

```sh
./push_swap 2 1 3 5 4
ra pb rra pb rra sa pa pa
```

O programa imprimirá a sequência de operações necessárias para ordenar os números.

![Image](https://github.com/user-attachments/assets/11c5f967-1f6e-44e9-a851-3f12205500dd)

## Operadores Disponíveis

- `sa` : Troca os dois primeiros elementos da pilha A.
- `sb` : Troca os dois primeiros elementos da pilha B.
- `ss` : Aplica `sa` e `sb` simultaneamente.
- `pa` : Move o primeiro elemento da pilha B para a pilha A.
- `pb` : Move o primeiro elemento da pilha A para a pilha B.
- `ra` : Rotaciona a pilha A para cima.
- `rb` : Rotaciona a pilha B para cima.
- `rr` : Aplica `ra` e `rb` simultaneamente.
- `rra` : Rotaciona a pilha A para baixo.
- `rrb` : Rotaciona a pilha B para baixo.
- `rrr` : Aplica `rra` e `rrb` simultaneamente.

## Estrutura do Diretório

```sh
push_swap/
├── algorithm/              # Algoritmo de ordenação
├── auxiliary function/     # Funções auxiliares
├── stack operations/       # Contém os operadores
├── Checker_linux           # Arquivo para testar resultados
├── Makefile                # Script de compilação
├── push_swap.c             # Arquivo contendo função main
├── push_swap.h             # Arquivos de cabeçalho
└── README.md               # Este arquivo
```
