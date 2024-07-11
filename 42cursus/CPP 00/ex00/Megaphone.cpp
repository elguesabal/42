#include <iostream>

int main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; i < argc; i++) {
		// std::transform(argv[i].begin(), argv[i].end(), argv[i].begin(), ::toupper);
		std::cout << argv[i] << std::endl;
	}
	return 0;
}