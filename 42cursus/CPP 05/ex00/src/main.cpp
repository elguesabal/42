#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat bureaucrat("vampeta", 1);
		// --bureaucrat;
		// std::cout << "name: " << bureaucrat.getName() << "grade: " << bureaucrat.getGrade() << std::endl;
		std::cout << bureaucrat;
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	return (0);
}