#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "../Contact/Contact.hpp"
#include <iomanip>
#include <string>

class PhoneBook {
private:
	Contact mContacts[8];
	int mContactCount;
public:
	PhoneBook(void);
	~PhoneBook(void);
	void exit(void);
	void add(void);
	void search(void);
};

#endif
