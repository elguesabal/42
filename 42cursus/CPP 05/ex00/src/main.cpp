#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat teste("vampeta", -1);
		std::cout << "name: " << teste.getName() << "grade: " << teste.getGrade() << std::endl;
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	return (0);
}