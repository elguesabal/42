#include "../includes/header.h"

Contact::Contact(int i) {
	index = i;
	fistName = "";
	lastName = "";
	nickName = "";
	number = "";
	secret = "";
}

void Contact::setContact(std::string fist, std::string last, std::string nick, std::string num, std::string sec) {
	fistName = fist;
	lastName = last;
	nickName = nick;
	number = num;
	secret = sec;
}

void Contact::printList(void) {
	std::cout << "\t" << "|" << std::right << std::setw(10) << index << "|";
	std::cout << std::setw(((fistName.size() > 10) ? 9 : 10)) << ((fistName.size() > 10) ? (std::cout << fistName.substr(0, 9), ".") : fistName) << "|";
	std::cout << std::setw(((lastName.size() > 10) ? 9 : 10)) << ((lastName.size() > 10) ? (std::cout << lastName.substr(0, 9), ".") : lastName) << "|";
	std::cout << std::setw(((nickName.size() > 10) ? 9 : 10)) << ((nickName.size() > 10) ? (std::cout << nickName.substr(0, 9), ".") : nickName) << "|";
	std::cout << std::endl;
}

void Contact::printContact(void) {
	std::cout << "Fist name: " << fistName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "nickName: " << nickName << std::endl;
	std::cout << "Number: " << number << std::endl;
	std::cout << "Secret: " << secret << std::endl;
}