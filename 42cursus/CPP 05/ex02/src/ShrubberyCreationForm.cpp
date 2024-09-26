#include "header.h"

// ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation", 145, 13) {

// }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 13), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : AForm(s.getName(), s.getGradeSigned(), s.getGradeExec()), _target(s._target) {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &s) {
	(void)s;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->getSigned()) {
		// throw
		std::cout << "nao ta assinado" << std::endl;
		return ;
	}

	if (executor.getGrade() > this->getGradeExec()) {
		// throw
		std::cout << "nao executado pq nao tem nota pra executar" << std::endl;
		return ;
	}


	std::fstream file;
	file.open((this->_target + "_shrubbery").c_str(), std::ios::out);
	if (!file)
		return ; // throw
	file << "      *           *           *           *" << std::endl;
	file << "     ***         ***         ***         ***" << std::endl;
	file << "    *****       *****       *****       *****" << std::endl;
	file << "   *******     *******     *******     *******" << std::endl;
	file << "  *********   *********   *********   *********" << std::endl;
	file << " *********** *********** *********** ***********" << std::endl;
	file << "    |            |            |            |" << std::endl;
	file.close();
}