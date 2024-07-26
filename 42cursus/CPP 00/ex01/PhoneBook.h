#ifndef PHONEBOOK_H_INCLUDED
#define PHONEBOOK_H_INCLUDED

#include "Contact.h"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int size();
		void add(std::string secret, std::string number, std::string nick, std::string last, std::string fist);

	private:
		Contact *contacts[9];

};

PhoneBook::PhoneBook(void) {
	for (int i = 0; i < 9; i++)
		contacts[i] = NULL;
}

PhoneBook::~PhoneBook(void) {
	for (int i = size(); i > -1; --i)
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




	// std::cout << i << std::endl;
	// std::cout << fist << std::endl;
	// std::cout << last << std::endl;
	// std::cout << nick << std::endl;
	// std::cout << number << std::endl;
	// std::cout << secret << std::endl;
}

#endif