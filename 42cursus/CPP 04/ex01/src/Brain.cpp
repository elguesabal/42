#include "header.h"

Brain::Brain(void) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "random ideas";
}

Brain::Brain(const Brain &brain) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
}

Brain &Brain::operator = (const Brain &brain) {
	if (this == &brain)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain(void) {

}