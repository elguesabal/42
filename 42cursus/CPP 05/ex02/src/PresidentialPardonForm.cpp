/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:37:22 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:37:31 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	(void)executor;
	std::cout << "Estimado " << this->_target << ", informamos que você foi perdoado por Zaphod Beeblebrox." << std::endl;
}