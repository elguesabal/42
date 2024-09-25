#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		// ShrubberyCreationForm(void);
		// ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &s);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &s);
		~ShrubberyCreationForm(void);

		// execute()

	private:

};

#endif