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



int main(void) {
	try {
		Bureaucrat bureaucrat("vampeta", 10);
		AForm form("formTeste", 100, 100);

		bureaucrat.signForm(form);
	} catch (const std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	return (0);
}