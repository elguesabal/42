#include "ScalarConverter.hpp"

void printChar(std::string input) {
	int num = std::stoi(input);
	char c = num;
	std::cout << "teste: " << c << std::endl;
}

void ScalarConverter::convert(std::string input) {
	// std::cout << input << std::endl;
	printChar(input);
}