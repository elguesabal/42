# Philosophers

- [Introdução](#introdução)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Compilação](#compilação)
- [Execução](#execução)
- [Regras](#regras)
- [Estrutura do Diretório](#estrutura-do-diretório)

## Introdução
O **Philosophers** é um projeto que tem como objetivo explorar conceitos de concorrência, threads e sincronização de processos, implementando o problema dos "Filósofos comensais".

## Tecnologias Utilizadas

- **Linguagem:** C
- **Bibliotecas:** `stdio`, `stdlib`, `unistd`, `sys/time`, `pthread`
- **Script:** Makefile
- **Sistema:** Unix/Linux

## Compilação
Para compilar o projeto, utilize o comando:

```sh
make
```
Isso gerará um executável chamado **philo**.

## Execução
O programa deve ser executado com os seguintes argumentos:

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- **number_of_philosophers**: Número de filósofos sentados à mesa.
- **time_to_die**: Tempo em milissegundos antes que um filósofo morra se não comer.
- **time_to_eat**: Tempo em milissegundos que um filósofo leva para comer.
- **time_to_sleep**: Tempo em milissegundos que um filósofo leva para dormir.
- **[number_of_times_each_philosopher_must_eat]**: (Opcional) Número de vezes que cada filósofo deve comer antes do programa terminar.

### Exemplo de uso
```sh
./philo 5 800 200 200 3
```

![Image](https://github.com/user-attachments/assets/d19c124c-c0b0-4714-a378-4a266f7e4c81)

## Regras
- Cada filósofo alterna entre os estados: **pensando**, **comendo** e **dormindo**.
- Um filósofo morre se passar mais de `time_to_die` milissegundos sem comer.
- Apenas um filósofo pode segurar um garfo por vez.
- Um filósofo precisa de dois garfos para comer.
- O programa deve terminar automaticamente se todos os filósofos comerem o número máximo de vezes especificado.

## Estrutura do Diretório
```
Philosophers/
├── func_aux/           # Funções auxiliares
├── philosopher/        # Gerenciamento de cada filósofo
├── Makefile            # Script de compilação
├── philosophers.c      # Arquivo contendo função main
├── philosophers.h      # Arquivo de cabeçalho
└── README.md           # Este arquivo
```
