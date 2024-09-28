#include "header.h"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : AForm(p.getName(), p.getGradeSigned(), p.getGradeExec()), _target(p._target) {

}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &p) {
	(void)p;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {

}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	// if (!this->getSigned())
	// 	throw (FormNotSigned());
	// if (executor.getGrade() > this->getGradeExec())
	// 	throw (GradeTooLow());
	(void)executor; // VERIFICACAO FEITA NA FUNCAO "void executeForm(AForm &form) const;" DENTRO DA CLASS Bureaucrat
	std::cout << "Estimado " << this->_target << ", informamos que você foi perdoado por Zaphod Beeblebrox." << std::endl;
}