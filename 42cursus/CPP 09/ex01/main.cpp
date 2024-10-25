#include "RPN.hpp"

// bool error(int argc, char **argv) {
// 	if (argc != 2)
// 		return (1);
// 	for (int i = 0; argv[1][i]; i++) {
// 		if ((argv[1][i] < '0' || argv[1][i] > '9') && argv[1][i] != ' ' && argv[1][i] != '+' && argv[1][i] != '-' && argv[1][i] != '*' && argv[1][i] != '/')
// 			return (1);
// 		if (i > 0 && argv[1][i] != ' ' && argv[1][i - 1] != ' ')
// 			return (1);
// 	}
// 	return (0);
// }

int main(int argc, char **argv) {
	// if (error(argc, argv)) {
	// 	std::cout << "Error" << std::endl;
	// 	return (0);
	// }
	if (argc != 2) {
		std::cout << "Error" << std::endl;
		return (0);
	}

	(void)argv;
	try {
		RPN teste1;
		RPN teste2(argv[1]);
		RPN teste3(teste2);
		RPN teste4 = teste2;
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	return (0);
}