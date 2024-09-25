#include "header.h"

AForm::AForm(std::string name, int gradeSigned, int gradeExec) : _name(name), _signed(0), _gradeSigned(gradeSigned), _gardeExec(gradeExec) {
	if (gradeSigned < 1 || gradeExec < 1) {
		throw (GradeTooHigh());
	} else if (gradeSigned > 150 || gradeExec > 150) {
		throw (GradeTooLow());
	}
}

AForm::AForm(const AForm &form) : _name(form._name), _signed(0), _gradeSigned(form._gradeSigned), _gardeExec(form._gardeExec) {

}

AForm &AForm::operator = (const AForm &form) {
	this->_signed = form._signed;
	return (*this);
}

AForm::~AForm(void) {

}

std::string AForm::getName(void) const {
	return (this->_name);
}

bool AForm::getSigned(void) const {
	return (this->_signed);
}

int AForm::getGradeSigned(void) const {
	return (this->_gradeSigned);
}

int AForm::getGradeExec(void) const {
	return (this->_gardeExec);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (this->_gradeSigned < bureaucrat.getGrade())
		throw (GradeTooLow());
	this->_signed = 1;
}

const char *AForm::GradeTooHigh::what(void) const throw() {
	return ("Exception: Nota muito alta!");
}

const char *AForm::GradeTooLow::what(void) const throw() {
	return ("Exception: Nota muito baixa!");
}

std::ostream &operator << (std::ostream &out, const AForm &form) {
	out << "Form: " << form.getName() << std::endl;
	out << "Signed: " << ((form.getSigned()) ? "True" : "False") << std::endl;
	out << "Nota mínima para ser assinada: " << form.getGradeSigned() << std::endl;
	out << "Nota mínima a ser executada: " << form.getGradeExec() << std::endl;
	return (out);
}