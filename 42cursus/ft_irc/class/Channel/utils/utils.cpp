#include "header.h"

unsigned int Channel::size(void) const {
	return (this->clients.size());
}