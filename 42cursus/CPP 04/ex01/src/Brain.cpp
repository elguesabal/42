#include "header.h"

Brain::Brain(void) {

}

Brain::Brain(const Brain &brain) {
	(void)brain;
}

Brain &Brain::operator = (const Brain &brain) {
	(void)brain;

	return (*this);
}

Brain::~Brain(void) {

}