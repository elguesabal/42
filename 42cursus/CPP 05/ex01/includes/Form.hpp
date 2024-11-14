/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:35:55 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:35:56 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

class Form {
	public:
		Form(std::string name, int gradeSigned, int gradeExec);
		Form(const Form &form);
		Form &operator = (const Form &form);
		~Form(void);

		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeSigned(void) const;
		int getGradeExec(void) const;
		void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator << (std::ostream &out, const Form &form);

#endif