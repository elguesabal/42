#ifndef	PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class PmergeMe {
	public:
		PmergeMe(void);
		PmergeMe(char **argv);
		~PmergeMe(void);

	private:
		void error(char **argv) const;
};

#endif