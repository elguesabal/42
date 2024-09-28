#include "header.h"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target) {

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
	// if (!this->getSigned())
	// 	throw (FormNotSigned());
	// if (executor.getGrade() > this->getGradeExec())
	// 	throw (GradeTooLow());
	(void)executor; // VERIFICACAO FEITA NA FUNCAO "void executeForm(AForm &form) const;" DENTRO DA CLASS Bureaucrat
	std::fstream file;
	file.open((this->_target + "_shrubbery").c_str(), std::ios::out);
	if (!file)
		throw (FileNotOpen());
	file << "      *           *           *           *" << std::endl;
	file << "     ***         ***         ***         ***" << std::endl;
	file << "    *****       *****       *****       *****" << std::endl;
	file << "   *******     *******     *******     *******" << std::endl;
	file << "  *********   *********   *********   *********" << std::endl;
	file << " *********** *********** *********** ***********" << std::endl;
	file << "      |           |           |           |" << std::endl;
	file.close();
}