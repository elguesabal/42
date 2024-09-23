#include "header.h"

Form::Form(std::string name, bool sign, int gradeSigned, int gradeExec) : _name(name), _signed(sign), _gradeSigned(gradeSigned), _gardeExec(gradeExec) {
	// AINDA TEM Q TRATAR O EXCEPTION
}

Form::Form(const Form &form) : _name(form._name), _signed(form._signed), _gradeSigned(form._gradeSigned), _gardeExec(form._gardeExec) {

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

std::ostream &operator << (std::ostream &out, const Form &form) {
	out << "Form: " << form.getName() << std::endl;
	out << "Signed: " << ((form.getSigned()) ? "True" : "False") << std::endl;
	out << "Nota mínima para ser assinada: " << form.getGradeSigned() << std::endl;
	out << "Nota mínima a ser executada: " << form.getGradeExec() << std::endl;
	return (out);
}