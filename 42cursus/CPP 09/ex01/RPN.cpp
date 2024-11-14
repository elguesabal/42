/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:43:10 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:43:11 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : _arg("") {

}

RPN::RPN(const char *argv) : _arg(argv) {
	if (error(argv))
		throw (std::runtime_error("Error"));
}

RPN::RPN(const RPN &rpn) : _arg(rpn._arg) {

}

RPN &RPN::operator = (const RPN &rpn) {
	if (this != &rpn)
		this->_arg = rpn._arg;
	return (*this);
}

RPN::~RPN(void) {

}

bool RPN::error(const char *argv) const {
	unsigned int i, number = 0, operators = 0;

	if (argv[0] == '+' || argv[0] == '-' || argv[0] == '*' || argv[0] == '/' || argv[2] == '+' || argv[2] == '-' || argv[2] == '*' || argv[2] == '/')
		return (1);
	for (i = 0; argv[i]; i++) {
		if ((argv[i] < '0' || argv[i] > '9') && argv[i] != ' ' && argv[i] != '+' && argv[i] != '-' && argv[i] != '*' && argv[i] != '/')
			return (1);
		if (i > 0 && argv[i] != ' ' && argv[i - 1] != ' ')
			return (1);
		if (argv[i] >= '0' && argv[i] <= '9')
			++number;
		if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
			++operators;
	}
	if (argv[i - 1] >= '0' && argv[i - 1] <= '9')
		return (1);
	if (operators + 1 != number)
		return (1);
	return (0);
}

void RPN::readArg(void) {
	for (int i = 0; this->_arg[i]; i++) {
		if (this->_arg[i] != ' ')
			this->_RPN.push_back(std::string(1, this->_arg[i]));
	}
}

std::string RPN::result(void) {
	std::ostringstream oss;

	while (this->_RPN.size() != 1) {
		for (std::deque<std::string>::iterator it = this->_RPN.begin(); it != this->_RPN.end(); ++it) {
			if (*it == "+" || *it == "-" || *it == "*" || *it == "/") {
				oss.str("");
				oss.clear();
				oss << operation(std::atoi((*(it - 2)).c_str()), std::atoi((*(it - 1)).c_str()), *it);
				this->_RPN.insert(it - 2, oss.str());
				this->_RPN.erase(it - 2, it + 1);
				break;
			}
		}
	}
	return (this->_RPN[0].c_str());
}

int RPN::operation(int n1, int n2, std::string &signal) const {
	switch (signal[0]) {
		case '+':
			return (n1 + n2);
		case '-':
			return (n1 - n2);
		case '*':
			return (n1 * n2);
		case '/':
			return (n1 / n2);
		default:
			return (0);
	}
}