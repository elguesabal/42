#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &p);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &p);
		~PresidentialPardonForm(void);

		void execute(const Bureaucrat &executor) const;

	private:
		const std::string _target;

};

#endif