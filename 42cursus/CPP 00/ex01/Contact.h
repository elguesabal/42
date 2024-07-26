#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

class Contact {
	public:
		Contact(int i);
		void setContact(std::string fist, std::string last, std::string nick, std::string num, std::string sec);

	private:
		int index;
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

#endif