#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	public:
		// ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &s);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &s);
		~ShrubberyCreationForm(void);

		void execute(const Bureaucrat &executor) const;

	private:
		const std::string _target;

};

#endif