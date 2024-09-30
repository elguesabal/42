#include "ScalarConverter.hpp"

void printChar(std::string input) {
	std::stringstream ss(input);
	int num;

	ss >> num;
	// std::cout << "teste: " << num << std::endl;
	std::cout << "char: ";
	if (num > 31 && num < 127) {
		char c = num;
		std::cout << c << std::endl;
	} else if (num < 32 || num > 128) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convert(std::string input) {
	if (input.compare("-inff") == 0 || input.compare("+inff") == 0 || input.compare("nanf") == 0 || input.compare("-inf") == 0 || input.compare("+inf") == 0 || input.compare("nan") == 0) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return ;
	}

	printChar(input);
}