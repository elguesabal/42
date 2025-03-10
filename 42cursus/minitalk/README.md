# Minitalk

- [Sobre o Projeto](#sobre-o-projeto)
- [Funcionalidades](#funcionalidades)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Como Compilar e Executar](#como-compilar-e-executar)
- [Estrutura do Diretório](#estrutura-do-diretório)
- [Exemplo de Uso](#exemplo-de-uso)

## Sobre o Projeto

O **Minitalk** é um projeto com objetivo de criar um sistema de comunicação entre processos utilizando sinais UNIX (**SIGUSR1** e **SIGUSR2**) para enviar mensagens de um cliente para um servidor.

## Funcionalidades

- O servidor recebe mensagens do cliente e as imprime na saída padrão.
- O cliente converte a mensagem em sinais e os envia ao servidor.
- Uso exclusivo de sinais UNIX para comunicação entre processos.

## Tecnologias Utilizadas

- **Linguagem:** C
- **Sinais UNIX:** SIGUSR1 e SIGUSR2
- **Script:** Makefile
- **Sistema:** Linux/macOS

## Como Compilar e Executar

### Compilando os programas

```sh
make
```

Isso gerará os binários `server` e `client`.

### Executando o Servidor

Para iniciar o servidor, execute:

```sh
./server
```

O PID do servidor será exibido no terminal.

### Enviando Mensagens com o Cliente

Com o servidor rodando, utilize o cliente para enviar mensagens:

```sh
./client <PID_DO_SERVIDOR> "Sua mensagem aqui"
```

Exemplo:

```sh
./client 12345 "Hello, Minitalk!"
```

O servidor deve exibir: `Hello, Minitalk!`

## Exemplo de Uso

1. Abra um terminal e inicie o servidor:
   ```sh
   ./server
   ```
2. Pegue o PID exibido e execute o cliente em outro terminal:
   ```sh
   ./client <PID> "Mensagem de teste"
   ```
3. A mensagem deve aparecer no terminal onde o servidor está rodando.

![Image](https://github.com/user-attachments/assets/4e3c99f5-a0e7-43e7-aa96-12b9f4dd924f)
