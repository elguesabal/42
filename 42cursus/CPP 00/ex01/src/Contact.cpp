#include "../includes/header.h"

Contact::Contact(int i) {
	index = i;
	_fistName = "";
	_lastName = "";
	_nickName = "";
	_number = "";
	_secret = "";
}

void Contact::setContact(std::string fist, std::string last, std::string nick, std::string num, std::string sec) {
	_fistName = fist;
	_lastName = last;
	_nickName = nick;
	_number = num;
	_secret = sec;
}

void Contact::printList(void) {
	std::cout << "\t" << "|" << std::right << std::setw(10) << index << "|";
	std::cout << std::setw(((_fistName.size() > 10) ? 9 : 10)) << ((_fistName.size() > 10) ? (std::cout << _fistName.substr(0, 9), ".") : _fistName) << "|";
	std::cout << std::setw(((_lastName.size() > 10) ? 9 : 10)) << ((_lastName.size() > 10) ? (std::cout << _lastName.substr(0, 9), ".") : _lastName) << "|";
	std::cout << std::setw(((_nickName.size() > 10) ? 9 : 10)) << ((_nickName.size() > 10) ? (std::cout << _nickName.substr(0, 9), ".") : _nickName) << "|";
	std::cout << std::endl;
}

void Contact::printContact(void) {
	std::cout << "Fist name: " << _fistName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "nickName: " << _nickName << std::endl;
	std::cout << "Number: " << _number << std::endl;
	std::cout << "Secret: " << _secret << std::endl;
}