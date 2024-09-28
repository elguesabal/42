#ifndef INTERN_HPP
#define INTERN_HPP

class Intern {
	public:
		Intern(void);
		~Intern(void);

		AForm *makeForm(std::string form, std::string target);
		AForm *newShrubbery(std::string target);
		AForm *newRobotomy(std::string target);
		AForm *newPresidential(std::string target);
};

#endif