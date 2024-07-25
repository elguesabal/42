#include "PhoneBook.h"

int main(void) {
	std::string buffer;
	PhoneBook *teste = new PhoneBook();

	waitCommand:
	std::cin >> buffer;

	if (buffer == "ADD") {
		std::cout << "add" << std::endl;
	} if (buffer == "SEARCH") {
		std::cout << "search" << std::endl;
	} else if (buffer == "EXIT") {
		std::cout << "exit" << std::endl;
		delete teste;
		return (0);
	}
	goto waitCommand;
}