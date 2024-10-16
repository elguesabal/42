#ifndef	MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T> class MutantStack: public std::stack<T> {
	public:
		MutantStack(void);
		MutantStack(const MutantStack &stack);
		MutantStack &operator = (const MutantStack &stack);
		virtual ~MutantStack(void);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void);
		iterator end(void);
};

#include "MutantStack.ipp"

#endif