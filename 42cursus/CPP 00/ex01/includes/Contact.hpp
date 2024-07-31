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

#endif