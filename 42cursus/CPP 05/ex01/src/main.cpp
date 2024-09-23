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



int main(void) {
	Form form("vampeta", 1, 10, 50);

	std::cout << form;

	return (0);
}