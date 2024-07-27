#ifndef PHONEBOOK_H_INCLUDED
#define PHONEBOOK_H_INCLUDED

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int size();
		void add(std::string secret, std::string number, std::string nick, std::string last, std::string fist);
		void search(void);

	private:
		Contact *contacts[8];

};

PhoneBook::PhoneBook(void) {
	for (int i = 0; i < 8; i++)
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

	if (i == 7) {
		delete contacts[0];
		for (int j = 0; j < 7; j++)
			contacts[j] = contacts[j + 1];
		contacts[7] = NULL;
	}

	contacts[i] = new Contact(i);

	contacts[i]->setContact(fist, last, nick, number, secret);
}

void PhoneBook::search(void) {
	int index;

	// std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "Fist name" << "|" << std::setw(10) << "Last name" << "|" << "Nickname" << "|" << std::endl;
	for (int i = 0; contacts[i]; i++) {
		contacts[i]->printList();
	}
	std::cout << "Digite o index do contato escolhido: ";
	std::cin >> index;
	if (index < 0 || index > size() - 1) {
		std::cout << "Contato inexistente!" << std::endl;
		return ;
	}
	contacts[index]->printContact();
}

#endif