#include "../includes/header.h"

PhoneBook::PhoneBook(void) {
	for (int i = 0; i < 9; i++)
		contacts[i] = NULL;
}

PhoneBook::~PhoneBook(void) {
	for (int i = size() - 1; i >= 0; --i)
		delete contacts[i];
}

int PhoneBook::size() {
	int i = 0;

	while (contacts[i])
		i++;
	return (i);
}

void PhoneBook::add(std::string secret, std::string number, std::string nick, std::string last, std::string fist) {
	int i = size();

	contacts[i] = new Contact(i);
	contacts[i]->setContact(fist, last, nick, number, secret);

	if (i > 7) {
		delete contacts[0];
		for (int j = 0; j < 8; j++) {
			contacts[j] = contacts[j + 1];
			contacts[j]->index = j;
		}
		contacts[8] = NULL;
	}

	std::cout << "Contato salvo" << std::endl;
}

void PhoneBook::search(void) {
	if (contacts[0] == NULL) {
		std::cout << "Nenhum contato salvo!" << std::endl;
		return ;
	}
	std::cout << "\v\t" << "|" << std::left << std::setw(10) << "Index" << "|" << std::setw(10) << "Nome" << "|" << std::setw(10) << "Sobrenome" << "|" << std::setw(10) << "Nick" << "|\v" << std::endl;
	for (int i = 0; contacts[i] != NULL; i++)
		contacts[i]->printList();
	std::cout << "\v";
	int index;
	do {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Digite um index valido: ";
		std::cin >> index;
	} while (std::cin.fail() || index < 0 || index > size() - 1);
	contacts[index]->printContact();
}