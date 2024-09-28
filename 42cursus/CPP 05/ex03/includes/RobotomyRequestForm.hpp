#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &r);
		RobotomyRequestForm &operator = (const RobotomyRequestForm &r);
		~RobotomyRequestForm(void);

		void execute(const Bureaucrat &executor) const;

	private:
		const std::string _target;

};

#endif