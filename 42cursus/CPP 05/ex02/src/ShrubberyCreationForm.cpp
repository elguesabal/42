#include "header.h"

// ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation", 145, 13){

// }

// ShrubberyCreationForm(std::string target);

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : AForm(s.getName(), s.getGradeSigned(), s.getGradeExec()) {
	(void)s;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &s) {
	(void)s;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

}