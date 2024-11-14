/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:38:49 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:38:50 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// int main(void) {
// 	try {
// 		Bureaucrat bureaucrat("vampeta", 1);
// 		// --bureaucrat;
// 		// std::cout << "name: " << bureaucrat.getName() << "grade: " << bureaucrat.getGrade() << std::endl;
// 		std::cout << bureaucrat;
// 	} catch (std::exception &error) {
// 		std::cout << error.what() << std::endl;
// 	}

// 	return (0);
// }



// int main(void) {
// 	try {
// 		Form form("vampeta", 0, 50);
// 		std::cout << form;
// 	} catch (std::exception &error) {
// 		std::cout << error.what() << std::endl;
// 	}

// 	return (0);
// }



// int main(void) {
// 	try {
// 		Bureaucrat bureaucrat("vampeta", 10);
// 		Form form("formTeste", 100, 100);

// 		bureaucrat.signForm(form);
// 	} catch (const std::exception &error) {
// 		std::cout << error.what() << std::endl;
// 	}

// 	return (0);
// }



// int main(void) {
// 	// try {
// 	// 	Bureaucrat bureaucrat("vampeta", 10);
// 	// 	// Bureaucrat bureaucrat("vampeta", 140);
// 	// 	// Bureaucrat bureaucrat("vampeta", 150);

// 	// 	ShrubberyCreationForm form("formulario teste");
// 	// 	bureaucrat.signForm(form);
// 	// 	form.execute(bureaucrat);
// 	// } catch (const std::exception &error) {
// 	// 	std::cout << error.what() << std::endl;
// 	// }



// 	// try {
// 	// 	Bureaucrat bureaucrat("vampeta", 10);
// 	// 	// Bureaucrat bureaucrat("vampeta", 50);
// 	// 	// Bureaucrat bureaucrat("vampeta", 150);

// 	// 	RobotomyRequestForm form("formulario teste");
// 	// 	bureaucrat.signForm(form);
// 	// 	form.execute(bureaucrat);
// 	// } catch (const std::exception &error) {
// 	// 	std::cout << error.what() << std::endl;
// 	// }



// 	// try {
// 	// 	Bureaucrat bureaucrat("vampeta", 1);
// 	// 	// Bureaucrat bureaucrat("vampeta", 10);
// 	// 	// Bureaucrat bureaucrat("vampeta", 50);

// 	// 	PresidentialPardonForm form("formulario teste");
// 	// 	bureaucrat.signForm(form);
// 	// 	form.execute(bureaucrat);
// 	// } catch (const std::exception &error) {
// 	// 	std::cout << error.what() << std::endl;
// 	// }



// 	try {
// 		Bureaucrat bureaucrat("vampeta", 1);
// 		// Bureaucrat bureaucrat("vampeta", 10);
// 		// Bureaucrat bureaucrat("vampeta", 50);

// 		PresidentialPardonForm form("formulario teste");
// 		bureaucrat.signForm(form);
// 		bureaucrat.executeForm(form);
// 	} catch (const std::exception &error) {
// 		std::cout << error.what() << std::endl;
// 	}

// 	return (0);
// }



int main(void) {
	try {
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		(void)rrf;
	} catch (const std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	return (0);
}