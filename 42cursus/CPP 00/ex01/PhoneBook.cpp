#include <iostream>
#include "Contact.h"
#include "PhoneBook.h"


std::string input(std::string str) {
	std::string response;

	std::cout << str;
	std::cin >> response;
	return (response);
}

int main(void) {
	std::string buffer;
	PhoneBook *list = new PhoneBook();
	// std::string fistName;
	// std::string lastName;
	// std::string nickName;
	// std::string number;
	// std::string secret;

	waitCommand:
	std::cout << "Digite um comando: ";
	std::cin >> buffer;
	if (buffer == "ADD") {
		// std::cout << "Nome: ";
		// std::cin >> fistName;
		// std::cout << "Sobrenome: ";
		// std::cin >> lastName;
		// std::cout << "Nick: ";
		// std::cin >> nickName;
		// std::cout << "Number: ";
		// std::cin >> number;
		// std::cout << "Secret: ";
		// std::cin >> secret;
		list->add(input("Nome: "), input("Sobrenome: "), input("Nick: "), input("Number: "), input("Secret: ")); // PQ AS FUNCOES SAO EXECUTADAS DA DIREITA PRA ESQUERDA?
		std::cout << "Contato salvo" << std::endl;
	} if (buffer == "SEARCH") {
		std::cout << "search" << std::endl;
	} else if (buffer == "EXIT") {
		std::cout << "exit" << std::endl;
		delete list;
		return (0);
	}
	goto waitCommand;
}