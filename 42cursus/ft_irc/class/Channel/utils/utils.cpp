#include "header.h"

/// @brief CONTA QUANTOS CLIENTES O CANAL TEM
/// @return RETORNA O TAMANHO DO CANAL
unsigned int Channel::size(void) const {
	return (this->clients.size());
}