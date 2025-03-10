# ft_printf

- [Sobre o Projeto](#sobre-o-projeto)
- [Funcionalidades Implementadas](#funcionalidades-implementadas)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Como Compilar e Executar](#como-compilar-e-executar)
- [Especificação das Funções](#especificacao-das-funcoes)

## Sobre o Projeto

O **ft_printf** é uma reprodução simplificada da função `printf` da biblioteca padrão do C. Este projeto tem como objetivo aprofundar o conhecimento sobre manipulação de variáveis, ponteiros e va_list, além de reforçar o entendimento sobre saída formatada em C.

## Funcionalidades Implementadas

- Impressão de caracteres e strings
- Impressão de números inteiros decimais e hexadecimais
- Manipulação de ponteiros
- Uso de `va_list` para tratar argumentos variáveis

## Tecnologias Utilizadas

- **Linguagem:** C
- **Compilador:** gcc
- **Script:** Makefile

## Como Compilar e Executar

### Compilando a Biblioteca

Para compilar a biblioteca e gerar o arquivo `libftprintf.a`, utilize:

```sh
make
```

Isso criará um arquivo `libftprintf.a`, que pode ser utilizado em outros projetos.

### Utilizando a Biblioteca em um Projeto

Inclua o cabeçalho `ft_printf.h` no seu código e compile com a biblioteca:

```sh
gcc main.c -L. -lftprintf
```

![Image](https://github.com/user-attachments/assets/531a20b2-1cda-48df-9224-865d3d663223)

## Especificação das Funções

A função `ft_printf` implementa um subconjunto das funcionalidades do `printf`, suportando os seguintes formatos:

```c
int ft_printf(const char *format, ...);
```

### Especificadores Suportados

| Especificador | Descrição |
|--------------|-------------|
| `%c` | Imprime um caractere |
| `%s` | Imprime uma string |
| `%p` | Imprime um ponteiro |
| `%d` | Imprime um inteiro decimal |
| `%i` | Imprime um inteiro decimal |
| `%u` | Imprime um inteiro decimal sem sinal |
| `%x` | Imprime um inteiro hexadecimal (minúsculo) |
| `%X` | Imprime um inteiro hexadecimal (maiúsculo) |
| `%%` | Imprime um `%` literal |

A implementação respeita as regras de comportamento de `printf`, mas não inclui funcionalidades avançadas como tratamento de largura de campo, precisão e alinhação.

---
