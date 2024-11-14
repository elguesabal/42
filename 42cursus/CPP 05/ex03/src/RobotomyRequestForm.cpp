/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:39:08 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:39:09 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	(void)executor;
	std::cout << "* ruídos de perfuração *" << std::endl;
	std::cout << "* ruídos de perfuração *" << std::endl;
	std::cout << "* ruídos de perfuração *" << std::endl;
	srand(time(0));
	std::cout << this->_target << ((rand() % 2 == 0) ? " foi robotizado com sucesso" : " não conseguiu ser robotizado") << std::endl;
}