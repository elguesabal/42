/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:39:45 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:39:46 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printChar(std::string input) {
	std::stringstream ss(input);
	int num;

	std::cout << "char: ";
	if (!(ss >> num)) {
		std::cout << "impossible" << std::endl;
	} else if (num > 31 && num < 127) {
		char c = num;
		std::cout << "'" << c << "'" << std::endl;
	} else {
		std::cout << "Non displayable" << std::endl;
	}
}

void printInt(std::string input) {
	std::stringstream ss(input);
	int num;

	std::cout << "int: ";
	if (ss >> num) {
		std::cout << num << std::endl;
	} else {
		std::cout << "nan" << std::endl;
	}
}

void printFloat(std::string input) {
	std::stringstream ss(input);
	float num;

	std::cout << "float: ";
	if (!(ss >> num)) {
		std::cout << "nanf" << std::endl;
		return ;
	}
	ss << num;
	std::string str = ss.str();
	std::size_t pos = str.find('f');
	if (pos != std::string::npos)
		str.erase(pos, 1);
	pos = str.find('.');
	if (pos == std::string::npos)
		str += ".0";
	std::cout << str << "f" << std::endl;
}

void printDouble(std::string input) {
	std::stringstream ss(input);
	double num;

	std::cout << "double: ";
	if (!(ss >> num)) {
		std::cout << "nan" << std::endl;
		return ;
	}
	ss << num;
	std::string str = ss.str();
	std::size_t pos = str.find('f');
	if (pos != std::string::npos)
		str.erase(pos, 1);
	pos = str.find('.');
	if (pos == std::string::npos)
		str += ".0";
	std::cout << str << std::endl;
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
	printInt(input);
	printFloat(input);
	printDouble(input);
}