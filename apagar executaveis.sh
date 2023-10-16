#!/bin/bash

# Diretório no qual você deseja excluir os arquivos .exe e .out
diretorio_alvo="/nfs/homes/joseanto/curso-C"

# Use o comando 'find' para localizar e excluir os arquivos .exe e .out
find "$diretorio_alvo" -type f \( -name "*.exe" -o -name "*.out" \) -exec rm -f {} \;

echo "Arquivos .exe e .out foram excluídos em $diretorio_alvo e subdiretórios."
