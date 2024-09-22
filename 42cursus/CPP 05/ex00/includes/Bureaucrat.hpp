#ifndef BUREAUCRTA_HPP
#define BUREAUCRTA_HPP

#include <iostream>

class Bureaucrat {
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator = (const Bureaucrat &bureaucrat);
		Bureaucrat &operator ++ (void);
		Bureaucrat &operator -- (void);
		~Bureaucrat(void);

		std::string getName(void) const;
		int getGrade(void) const;

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

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif