#include "header.h"

Form::Form(std::string name, int gradeSigned, int gradeExec) : _name(name), _signed(0), _gradeSigned(gradeSigned), _gardeExec(gradeExec) {
	if (gradeSigned < 1 || gradeExec < 1) {
		throw (GradeTooHigh());
	} else if (gradeSigned > 150 || gradeExec > 150) {
		throw (GradeTooLow());
	}
}

Form::Form(const Form &form) : _name(form._name), _signed(0), _gradeSigned(form._gradeSigned), _gardeExec(form._gardeExec) {

}

Form &Form::operator = (const Form &form) {
	this->_signed = form._signed;
	return (*this);
}

Form::~Form(void) {

}

std::string Form::getName(void) const {
	return (this->_name);
}

bool Form::getSigned(void) const {
	return (this->_signed);
}

int Form::getGradeSigned(void) const {
	return (this->_gradeSigned);
}

int Form::getGradeExec(void) const {
	return (this->_gardeExec);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (this->_gradeSigned < bureaucrat.getGrade())
		throw (GradeTooLow());
	this->_signed = 1;
}

const char *Form::GradeTooHigh::what(void) const throw() {
	return ("Exception: Nota muito alta!");
}

const char *Form::GradeTooLow::what(void) const throw() {
	return ("Exception: Nota muito baixa!");
}

std::ostream &operator << (std::ostream &out, const Form &form) {
	out << "Form: " << form.getName() << std::endl;
	out << "Signed: " << ((form.getSigned()) ? "True" : "False") << std::endl;
	out << "Nota mínima para ser assinada: " << form.getGradeSigned() << std::endl;
	out << "Nota mínima a ser executada: " << form.getGradeExec() << std::endl;
	return (out);
}