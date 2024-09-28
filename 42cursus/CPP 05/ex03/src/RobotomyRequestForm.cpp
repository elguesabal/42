#include "header.h"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : AForm(r.getName(), r.getGradeSigned(), r.getGradeExec()), _target(r._target) {

}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &r) {
	(void)r;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	// if (!this->getSigned())
	// 	throw (FormNotSigned());
	// if (executor.getGrade() > this->getGradeExec())
	// 	throw (GradeTooLow());
	(void)executor; // VERIFICACAO FEITA NA FUNCAO "void executeForm(AForm &form) const;" DENTRO DA CLASS Bureaucrat
	std::cout << "* ruídos de perfuração *" << std::endl;
	std::cout << "* ruídos de perfuração *" << std::endl;
	std::cout << "* ruídos de perfuração *" << std::endl;
	srand(time(0));
	std::cout << this->_target << ((rand() % 2 == 0) ? " foi robotizado com sucesso" : " não conseguiu ser robotizado") << std::endl;
}