#include "header.h"

Intern::Intern(void) {

}

Intern::~Intern(void) {

}

AForm *Intern::newShrubbery(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::newRobotomy(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::newPresidential(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target) {
	std::string	s[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*p[3])(std::string) = {&Intern::newShrubbery, &Intern::newRobotomy, &Intern::newPresidential};
	int i = 0;

	while (i < 4 && s[i].compare(form) != 0)
		i++;
	if (i < 3)
	{
		std::cout << "Estagiário criado " << s[i] << std::endl;
		return((this->*p[i])(target));
	}
	else
		std::cout << "Exception: " << form << " não é um nome válido para um formulário!" << std::endl;
	return (NULL);
}