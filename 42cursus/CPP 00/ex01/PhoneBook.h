#ifndef PHONEBOOK_H_INCLUDED
#define PHONEBOOK_H_INCLUDED

#include "Contact.h"

class PhoneBook {
	public:
		PhoneBook(void);
		void add(std::string fist, std::string last, std::string nick, std::string number, std::string secret);

	private:
		Contact *contacts[9];

};

PhoneBook::PhoneBook(void) {
	for (int i = 0; i < 9; i++) {
		contacts[i] = new Contact(i);
	}
}

void PhoneBook::add(std::string fist, std::string last, std::string nick, std::string number, std::string secret) {
	std::cout << fist << std::endl;
	std::cout << last << std::endl;
	std::cout << nick << std::endl;
	std::cout << number << std::endl;
	std::cout << secret << std::endl;
}

#endif