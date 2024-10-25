#include "RPN.hpp"

RPN::RPN(void) : _arg("") {
	std::cout << "class criada" << std::endl;
}

RPN::RPN(const char *argv) : _arg(argv) {
	if (error(argv))
		throw (std::runtime_error("Error"));
	std::cout << "class criada" << std::endl;
}

RPN::RPN(const RPN &rpn) : _arg(rpn._arg) {
	std::cout << "class criada" << std::endl;
}

RPN &RPN::operator = (const RPN &rpn) {
	if (this != &rpn)
		this->_arg = rpn._arg;
	std::cout << "class criada" << std::endl;
	return (*this);
}

RPN::~RPN(void) {

}

bool RPN::error(const char *argv) const {
	for (int i = 0; argv[i]; i++) {
		if ((argv[i] < '0' || argv[i] > '9') && argv[i] != ' ' && argv[i] != '+' && argv[i] != '-' && argv[i] != '*' && argv[i] != '/')
			return (1);
		if (i > 0 && argv[i] != ' ' && argv[i - 1] != ' ')
			return (1);
	}
	return (0);
}

void RPN::readArg(void) {
	for (int i = 0; arg[i]; i++) {
		// if (arg[i] != ) // PAREI AKI PQ DEU PROBLEMA NA LUZ
	}
}