/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:39:16 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:39:17 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : AForm(s.getName(), s.getGradeSigned(), s.getGradeExec()), _target(s._target) {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &s) {
	(void)s;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	(void)executor;
	std::fstream file;
	file.open((this->_target + "_shrubbery").c_str(), std::ios::out);
	if (!file)
		throw (FileNotOpen());
	file << "      *           *           *           *" << std::endl;
	file << "     ***         ***         ***         ***" << std::endl;
	file << "    *****       *****       *****       *****" << std::endl;
	file << "   *******     *******     *******     *******" << std::endl;
	file << "  *********   *********   *********   *********" << std::endl;
	file << " *********** *********** *********** ***********" << std::endl;
	file << "      |           |           |           |" << std::endl;
	file.close();
}