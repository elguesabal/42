#ifndef	MUTANTSTACK_IPP
#define MUTANTSTACK_IPP

#include "MutantStack.hpp"

template <typename T> MutantStack<T>::MutantStack(void) : std::stack<T>() {

}

template <typename T> MutantStack<T>::MutantStack(const MutantStack &stack) : std::stack<T>(stack) {

}

template <typename T> MutantStack<T> &MutantStack<T>::operator = (const MutantStack &stack) {
	if (this != &stack)
		this->c = stack.c;
	return (*this);
}

template <typename T> MutantStack<T>::~MutantStack(void) {

}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
	return (this->c.begin());
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end(void) {
	return (this->c.end());
}

#endif