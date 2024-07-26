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

	waitCommand:
	std::cout << "Digite um comando: ";
	std::cin >> buffer;
	if (buffer == "ADD") {
		list->add(input("Secret: "), input("Number: "), input("Nick: "), input("Sobrenome: "), input("Nome: ")); // PQ AS FUNCOES SAO EXECUTADAS DA DIREITA PRA ESQUERDA?
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