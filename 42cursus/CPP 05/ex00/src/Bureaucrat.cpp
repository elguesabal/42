#include "Bureaucrat.hpp"

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
	// this->_name = bureaucrat._name;
	// this->_grade = bureaucrat._grade;
	(void)bureaucrat;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {

}

std::string Bureaucrat::getName(void) {
	return (this->_name);
}

int Bureaucrat::getGrade(void) {
	return (this->_grade);
}

const char *Bureaucrat::GradeTooHigh::what(void) const throw() {
	return ("Exception: Nota muito alta!");
}

const char *Bureaucrat::GradeTooLow::what(void) const throw() {
	return ("Exception: Nota muito baixa!");
}