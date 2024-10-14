#ifndef	MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T> class MutantStack: public std::stack<T> {
	public:
		MutantStack(void);
		MutantStack(const MutantStack &stack);
		virtual ~MutantStack();

};

#include "MutantStack.ipp"

#endif