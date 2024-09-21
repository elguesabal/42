#ifndef BUREAUCRTA_HPP
#define BUREAUCRTA_HPP

#include <iostream>

class Bureaucrat {
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator = (const Bureaucrat &bureaucrat);
		~Bureaucrat(void);

		std::string getName(void);
		int getGrade(void);

		class GradeTooHigh : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class GradeTooLow : public std::exception {
			public:
				const char *what(void) const throw();
		};

	private:
		const std::string _name;
		int _grade;

};

#endif