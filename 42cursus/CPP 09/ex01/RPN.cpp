#include "RPN.hpp"

RPN::RPN(void) : _arg("") {
	// std::cout << "class criada" << std::endl;
}

RPN::RPN(const char *argv) : _arg(argv) {
	if (error(argv))
		throw (std::runtime_error("Error"));
	// std::cout << "class criada" << std::endl;
}

RPN::RPN(const RPN &rpn) : _arg(rpn._arg) {
	// std::cout << "class criada" << std::endl;
}

RPN &RPN::operator = (const RPN &rpn) {
	if (this != &rpn)
		this->_arg = rpn._arg;
	// std::cout << "class criada" << std::endl;
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

	// for (std::deque<char>::iterator it = this->_RPN.begin(); it != this->_RPN.end(); ++it)
	// 	std::cout << "teste: " << *it << std::endl;
}

int RPN::result(void) {
	// int n1, n2, signal;
			// std::cout << "teste" << std::endl;

	while (this->_RPN.size() != 1) {
		// for (int i = 0, std::deque<std::string> it = this->_RPN.begin(); ; i++) {

		// }

		// if (this->_RPN.size() > 3 && this->_RPN[0])

		for (unsigned int i = 0; i < this->_RPN.size(); i++) {
			if (this->_RPN[i] == "+" || this->_RPN[i] == "-" || this->_RPN[i] == "*" || this->_RPN[i] == "/") { // AGORA TENHO Q SALVAR OS DOIS NUMEROS ANTES DO PRIMEIRO OPERADOR
				std::cout << "operacao q eu tenho q fazer => " << this->_RPN[i] << " com os numero => " << this->_RPN[i - 2] << " " << this->_RPN[i - 1] << std::endl;
				this->_RPN.pop_back();
				this->_RPN.pop_back();
				break;
			}
		}
	}
	return (10);
}