#ifndef	MUTANTSTACK_IPP
#define MUTANTSTACK_IPP

#include "MutantStack.hpp"

template <typename T> MutantStack<T>::MutantStack(void) : std::stack<T>() {

}

template <typename T> MutantStack<T>::MutantStack(const MutantStack &stack) : std::stack<T>(stack) {
	// *this = stack;
}

template <typename T> MutantStack<T> &MutantStack<T>::operator = (const MutantStack &stack) {
	// NAO COPIAR ELE MESMO
	this->c = stack.c; // DE ONDE SAIU ESSE c???
	return (*this);
}

template <typename T> MutantStack<T>::~MutantStack(void) {

}


template <typename T> void MutantStack<T>::print(void) {
	// for (std::stack <int>::iterator it = *this->begin(); it != *this->end(); it++)
	// 	std::cout << *it << std::endl;

	// std::cout << this->c.begin() << std::endl;

	// std::cout << this->top() << std::endl;

	// for (MutantStack<T> temp = *this; !temp.empty(); temp.pop())
	// 	std::cout << temp.top() << std::endl;

	MutantStack<T> temp = *this;
	while (!temp.empty()) {
		std::cout << temp.top() << std::endl;
		temp.pop();
	}
}

#endif