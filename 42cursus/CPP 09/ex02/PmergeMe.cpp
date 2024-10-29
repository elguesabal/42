#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {

}

PmergeMe::PmergeMe(char **argv) {
	error(argv);
	
}

PmergeMe::~PmergeMe(void) {

}

void PmergeMe::error(char **argv) const {
	for (int i = 0; argv[i]; i++) {
		if (argv[i][0] == '-')
			throw (std::runtime_error("Error: numero negativo nao aceito"));
		for (int j = 0; argv[i][j]; j++) {
			if (argv[i][j] < '0' || argv[i][j] > '9')
				throw (std::runtime_error("Error: argumentos devem ser apenas numeros"));
		}
	}
}