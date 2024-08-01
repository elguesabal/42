#ifndef PHONEBOOK_H_INCLUDED
#define PHONEBOOK_H_INCLUDED

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add(std::string secret, std::string number, std::string nick, std::string last, std::string fist);
		void search(void);

	private:
		Contact *_contacts[9];
		int size();

};

#endif