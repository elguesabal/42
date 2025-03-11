# so_long

- [Introdução](#introdução)
- [Objetivo](#objetivo)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Instalação e Compilação](#instalação-e-compilação)
- [Execução](#execução)
- [Estrutura do Diretório](#estrutura-do-diretório)

## Introdução
O **so_long** é um projeto que consiste na criação de um jogo simples em 2D usando a biblioteca **MiniLibX**. O jogo é baseado em um mapa fornecido como arquivo de entrada e segue regras básicas para movimentação e coleta de itens.

## Objetivo
O objetivo principal do projeto é desenvolver um jogo em que o jogador deve coletar todos os itens e chegar à saída, respeitando as regras de movimentação definidas pelo mapa. O projeto reforça conceitos como:
- Manipulação de arquivos
- Controle de eventos
- Uso da biblioteca gráfica **MiniLibX**
- Geração e manipulação de mapas

## Tecnologias Utilizadas

- **Linguagem:** C
- **Bibliotecas:** `stdio`, `stdlib`, `unistd`, `fcntl`, `minilibx-linux/mlx`
- **Script:** Makefile
- **Sistema:** Unix/Linux

## Instalação e Compilação
Compile o projeto:
   ```sh
   make
   ```
   O executável `so_long` será gerado no diretório principal.

## Execução
Para rodar o jogo, utilize:
```sh
./so_long map.ber
```

![Image](https://github.com/user-attachments/assets/a2cd8ebd-a674-4c1f-9c7a-bf6b34fbe1ce)

## Estrutura do Diretório
```
so_long/
├── events/              # Manipulação de eventos do teclado
├── ft_aux/              # Funções auxiliares
├── img/                 # Sprites recortadas
├── minilibx-linux/      # Biblioteca gráfica
├── rendering/           # Funções de renderização de imagens
├── verification/        # Validador do mapa
├── Makefile             # Script de compilação
├── maps.ber             # Mapa do jogo
├── so_long.c            # Arquivo contendo função main
├── so_long.h            # Arquivo de cabeçalho
├── sprites.png          # Sprites do jogo compactadas
├── README.md            # Este arquivo
```

