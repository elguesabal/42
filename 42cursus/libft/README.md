# Libft

- [Sobre o Projeto](#sobre-o-projeto)
- [Funcionalidades Implementadas](#funcionalidades-implementadas)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Como Compilar e Executar](#como-compilar-e-executar)
- [Funções Implementadas](#funcoes-implementadas)

## Sobre o Projeto

A **libft** é uma biblioteca de funções desenvolvida em C que replica diversas funções da biblioteca padrão do Linux. Este projeto tem como objetivo aprimorar o entendimento sobre manipulação de strings, memória e entrada/saída em C.

## Funcionalidades Implementadas

- Funções para manipulação de caracteres e strings
- Manipulação de memória
- Conversão de tipos
- Alocação dinâmica de memória
- Funções de escrita em arquivos

## Tecnologias Utilizadas

- **Linguagem:** C
- **Compilador:** gcc
- **Script:** Makefile

## Como Compilar e Executar

### Compilando a Biblioteca

```sh
make
```

Isso gerará um arquivo `libft.a`, que pode ser incluído em outros projetos.

![Image](https://github.com/user-attachments/assets/deba5e01-54d1-4f34-9927-eabec8e81dbd)

### Utilizando a Biblioteca em um Projeto

Inclua o cabeçalho `libft.h` no seu código e compile com a biblioteca:

```sh
gcc main.c -L. -lft
```

![Image](https://github.com/user-attachments/assets/7f961b36-cfcc-42ff-ae1c-14329d25b89e)

## Funções Implementadas

### Funções de Caracteres

```c
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
```

### Funções de Strings

```c
size_t ft_strlen(const char *str);
char *ft_strchr(const char *str, int c);
char *ft_strrchr(const char *str, int c);
int ft_strncmp(const char *str1, const char *str2, size_t n);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
size_t ft_strlcat(char *dest, const char *src, size_t size);
char *ft_strnstr(const char *str1, const char *str2, size_t n);
char *ft_strdup(const char *str);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char*));
```

### Funções de Memória

```c
void *ft_memset(void *str, int c, size_t size);
void ft_bzero(void *str, size_t size);
void *ft_memcpy(void *dest, const void *src, size_t size);
void *ft_memmove(void *dest, const void *src, size_t size);
void *ft_memchr(const void *ptr, int c, size_t n);
int ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void *ft_calloc(size_t n_elements, size_t size);
```

### Funções de Escrita em Arquivo

```c
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
```

### Conversão de Tipos

```c
int ft_atoi(const char *str);
```
