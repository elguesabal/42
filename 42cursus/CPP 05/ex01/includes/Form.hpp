#ifndef FORM_HPP
#define FORM_HPP

class Form {
	public:
		Form(std::string name, bool sign, int gradeSigned, int gradeExec);
		Form(const Form &form);
		Form &operator = (const Form &form);
		~Form(void);
		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeSigned(void) const;
		int getGradeExec(void) const;

	private:
		const std::string _name;
		bool _signed;
		const int _gradeSigned;
		const int _gardeExec;

};

std::ostream &operator << (std::ostream &out, const Form &form);

#endif