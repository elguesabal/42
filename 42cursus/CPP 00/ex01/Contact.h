#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

class Contact {
	public:
		Contact(int i);

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

#endif