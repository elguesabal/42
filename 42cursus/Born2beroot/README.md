# Born2beroot

- [Sobre o Projeto](#sobre-o-projeto)
- [Requisitos do Projeto](#requisitos-do-projetos)
- [Como Configurar](#como-configurar)
- [Políticas de Segurança](#políticas-de-segurança)
- [Script de Monitoramento](#script-de-monitoramento)
- [Como Testar o Servidor](#como-testar-o-servidor)
- [Conclusão](#conclusão)

## Sobre o Projeto

O **Born2beroot** é um projeto que tem como objetivo ensinar a configuração de um servidor Linux seguro e funcional. Durante o projeto, é necessário criar uma máquina virtual com Debian ou CentOS, configurar diversos serviços essenciais e aplicar boas práticas de segurança.

## Requisitos do Projeto

O projeto exige que o sistema seja configurado com as seguintes especificações:
- Uso de uma máquina virtual (VirtualBox ou UTM)
- Instalação de Debian (ou CentOS)
- Particionamento de disco em conformidade com os padrões do projeto
- Uso do LVM (Logical Volume Manager)
- Criação de um novo usuário com permissões limitadas
- Configuração de sudo com regras de segurança
- Configuração de SSH para acesso remoto
- Implementação de políticas de senha seguras
- Uso de um script para monitoramento do sistema

## Como Configurar

### Criando a Máquina Virtual

1. Instale o VirtualBox ou UTM (para Mac M1/M2)
2. Baixe a imagem ISO do Debian (ou CentOS)
3. Crie uma nova máquina virtual com as seguintes especificações:
   - **Nome:** Born2beroot
   - **RAM:** 1024MB (ou mais)
   - **Disco:** 8GB (ou mais)

### Instalação do Sistema Operacional

1. Inicialize a VM e inicie a instalação do Debian
2. Escolha o modo de particionamento manual e configure conforme exigido:
   - **/boot**: 512MB (ext2)
   - **/ (root)**, **swap**, e **/home** gerenciados pelo LVM
3. Instale apenas os pacotes essenciais, sem interface gráfica

### Configurações Pós-Instalação

#### Criando um Novo Usuário

```sh
adduser usuario42
```

#### Configurando o Sudo

```sh
usermod -aG sudo usuario42
```

Edite o arquivo `/etc/sudoers` para incluir:
```sh
usuario42 ALL=(ALL) ALL
```

#### Configurando o SSH

```sh
sudo apt update && sudo apt install openssh-server
sudo systemctl enable ssh
sudo systemctl start ssh
```

Edite `/etc/ssh/sshd_config` e altere:
```sh
PermitRootLogin no
PasswordAuthentication yes
```

Reinicie o serviço:
```sh
sudo systemctl restart ssh
```

### Políticas de Segurança

Instale o **libpam-pwquality**:
```sh
sudo apt install libpam-pwquality
```

Edite `/etc/security/pwquality.conf`:
```sh
minlen = 10
dcredit = -1
ucredit = -1
ocredit = -1
lcredit = -1
```

### Script de Monitoramento

Crie um script para exibir informações do sistema:
```sh
#!/bin/bash

wall "
# Arquitetura: $(uname -m)
# CPU: $(nproc) núcleos
# Memória livre: $(free -m | awk '/Mem:/ {print $4}') MB
# Espaço em disco livre: $(df -h / | awk 'NR==2 {print $4}')
# Endereço IP: $(hostname -I | awk '{print $1}')
# Status do SSH: $(systemctl is-active ssh)
"
```

Salve como `monitor.sh` e torne-o executável:
```sh
chmod +x monitor.sh
```

Adicione ao crontab para rodar a cada 10 minutos:
```sh
crontab -e
*/10 * * * * /caminho/para/monitor.sh
```

## Como Testar o Servidor

- **Verifique o acesso via SSH:**
  ```sh
  ssh usuario42@IP_DO_SERVIDOR
  ```
- **Confirme as permissões do sudo:**
  ```sh
  sudo whoami
  ```
- **Execute o script de monitoramento manualmente:**
  ```sh
  ./monitor.sh
  ```

## Conclusão

O projeto **Born2beroot** ajuda a desenvolver competências essenciais para administração de sistemas Linux, ensinando boas práticas de segurança e gerenciamento de servidores. Seguindo este guia, você configurou um sistema Linux funcional e seguro.
