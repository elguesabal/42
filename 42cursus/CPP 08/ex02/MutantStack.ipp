#ifndef	MUTANTSTACK_IPP
#define MUTANTSTACK_IPP

#include "MutantStack.hpp"

template <typename T> MutantStack<T>::MutantStack(void) {

}

template <typename T> MutantStack<T>::MutantStack(const MutantStack &stack) {
    *this = stack;
}

template <typename T> MutantStack<T>::~MutantStack(void) {

}

#endif