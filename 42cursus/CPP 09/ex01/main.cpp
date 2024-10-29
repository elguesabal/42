#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error" << std::endl;
		return (0);
	}
	try {
		RPN rpn(argv[1]);

		rpn.readArg();
		std::cout << rpn.result() << std::endl;
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	return (0);
}