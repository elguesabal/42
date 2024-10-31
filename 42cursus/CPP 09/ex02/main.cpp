#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Error: numero de argumentos invalidos" << std::endl;
		return (0);
	}
	try {
		PmergeMe teste1(argv + 1);
		PmergeMe teste2(teste1);
		PmergeMe teste3;

		teste3 = teste1;
		teste3.fordJohnson();
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	return (0);
}