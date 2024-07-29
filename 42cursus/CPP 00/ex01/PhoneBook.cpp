#include <iostream>
#include <iomanip>
#include <limits>
#include "Contact.h"
#include "PhoneBook.h"

std::string input(std::string str) {
	std::string response = "";

	std::cout << str;
	std::cin >> response;
	return (response);
}

int main(void) {
	std::string buffer;
	PhoneBook *list = new PhoneBook();

	waitCommand:
	buffer = input("Digite um comando: ");
	if (buffer == "ADD") {
		list->add(input("Secret: "), input("Number: "), input("Nick: "), input("Sobrenome: "), input("Nome: ")); // PQ AS FUNCOES SAO EXECUTADAS DA DIREITA PRA ESQUERDA?
		std::cout << "Contato salvo" << std::endl;
	} if (buffer == "SEARCH") {
		list->search();
	} else if (buffer == "EXIT") {
		std::cout << "exit" << std::endl;
		delete list;
		return (0);
	}
	goto waitCommand;
}