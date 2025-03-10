# Get Next Line

## Sumário
- [Sobre o Projeto](#sobre-o-projeto)
- [Funcionalidades](#funcionalidades)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Como Compilar e Usar](#como-compilar-e-usar)
- [Protótipos das Funções](#protótipos-das-funções)

## Sobre o Projeto

O **Get Next Line** é um projeto que tem como objetivo implementar uma função em C capaz de ler uma linha de um descritor de arquivo de maneira eficiente, independentemente do tamanho do buffer.

## Funcionalidades

- Lê e retorna a próxima linha de um arquivo a cada chamada da função.
- Funciona com diferentes tamanhos de **BUFFER_SIZE**.
- Suporta leitura a partir de arquivos e entrada padrão.
- Gerencia múltiplos descritores de arquivos simultaneamente.

## Tecnologias Utilizadas

- **Linguagem:** C
- **Compilador:** GCC
- **Script:** Makefile
- **Sistema:** Unix-based (Linux/macOS)

## Como Compilar e Usar

### Compilando

Use um compilador compatível com C:

```sh
make
```

### Usando em um Programa

Inclua o **get_next_line.h** no seu programa e compile junto com a biblioteca:

```sh
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
./a.out
```

![Image](https://github.com/user-attachments/assets/2ea40e93-ee38-457c-b6dd-ca8b607a7f7e)

## Protótipos das Funções

```c
char *get_next_line(int fd);
```

- **Parâmetro:** `fd` - O descritor de arquivo a ser lido.
- **Retorno:** Uma string contendo a próxima linha lida do arquivo, ou `NULL` se o final do arquivo for atingido ou ocorrer um erro.

