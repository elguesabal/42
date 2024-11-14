/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:35:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:35:36 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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