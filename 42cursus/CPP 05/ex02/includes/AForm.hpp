#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;

class AForm {
	public:
		AForm(std::string name, int gradeSigned, int gradeExec);
		AForm(const AForm &form);
		AForm &operator = (const AForm &form);
		virtual ~AForm(void);

		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeSigned(void) const;
		int getGradeExec(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;

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
		bool _signed;
		const int _gradeSigned;
		const int _gardeExec;

};

std::ostream &operator << (std::ostream &out, const AForm &form);

#endif