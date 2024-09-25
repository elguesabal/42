#include "header.h"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade > 150) {
		throw (GradeTooHigh());
	} else if (grade < 1) {
		throw (GradeTooLow());
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name), _grade(bureaucrat._grade) {

}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &bureaucrat) {
	this->_grade = bureaucrat._grade;
	return (*this);
}

Bureaucrat &Bureaucrat::operator ++ (void) {
	if (this->_grade == 150)
		throw (GradeTooHigh());
	(this->_grade)++;
	return (*this);
}

Bureaucrat &Bureaucrat::operator -- (void) {
	if (this->_grade == 1)
		throw (GradeTooLow());
	(this->_grade)--;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {

}

std::string Bureaucrat::getName(void) const {
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " assinou " << form.getName() << std::endl;
	} catch (const std::exception &error) {
		std::cout << this->_name << " não conseguiu assinar " << form.getName() << " por ";
		std::cout << error.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHigh::what(void) const throw() {
	return ("Exception: Nota muito alta!");
}

const char *Bureaucrat::GradeTooLow::what(void) const throw() {
	return ("Exception: Nota muito baixa!");
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", nota do burocrata " << bureaucrat.getGrade() << std::endl;
	return (out);
}