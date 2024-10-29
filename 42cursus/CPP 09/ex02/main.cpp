#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Error: numero de argumentos invalidos" << std::endl;
		return (0);
	}
	try {
		PmergeMe teste(argv + 1);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	return (0);
}