#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
private:
	std::string mFirstName;
	std::string mLastName;
	std::string mNickname;
	std::string mPhoneNumber;
	std::string mSecret;

public:
	Contact(void);
	~Contact(void);
	void setFirstName(std::string input);
	void setLastName(std::string input);
	void setNickname(std::string input);
	void setPhoneNumber(std::string input);
	void setSecret(std::string input);

	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickname(void);
	std::string getPhoneNumber(void);
	std::string getSecret(void);
};

#endif