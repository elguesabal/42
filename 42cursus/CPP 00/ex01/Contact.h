#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

class Contact {
	public:
		int index;
		Contact(int i);
		void setContact(std::string fist, std::string last, std::string nick, std::string num, std::string sec);
		void printList(void);
		void printContact(void);

	private:
		std::string fistName;
		std::string lastName;
		std::string nickName;
		std::string number;
		std::string secret;

};

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
	std::cout << "|" << std::left << std::setw(10) << index << "|";
	std::cout << std::left << std::setw(10) << fistName << "|";
	std::cout << std::left << std::setw(10) << lastName << "|";
	std::cout << std::left << std::setw(10) << nickName << "|" << std::endl;
}

void Contact::printContact(void) {
	std::cout << "Fist name: " << fistName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "nickName: " << nickName << std::endl;
	std::cout << "Number: " << number << std::endl;
	std::cout << "Secret: " << secret << std::endl;
}

#endif