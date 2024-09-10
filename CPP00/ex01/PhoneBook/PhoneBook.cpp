#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): mContactCount(0) {
	return;
}

PhoneBook::~PhoneBook() {
	return;
}

std::string trim(std::string str) {
	int start = str.find_first_not_of(" \t\n\r\f\v");
	if (start == (int)std::string::npos)
		return "";
	int end = str.find_last_not_of(" \t\n\r\v");
	return str.substr(start, end - start + 1);
}

bool isStringNumeric(std::string str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

std::string getAlphaInput(std::string prompt) {
	std::string input;

	do {
		std::cout << prompt;
		getline(std::cin, input);
		input = trim(input);
	} while (input.empty());
	return input;
}

std::string getNumInput(std::string prompt) {
	std::string input;

	do {
		std::cout << prompt;
		getline(std::cin, input);
		input = trim(input);
	} while (input.empty() || !isStringNumeric(input));
	return input;
}

Contact createContact(void) {
	Contact contact;

	contact.setFirstName(getAlphaInput("Enter first name: "));
	contact.setLastName(getAlphaInput("Enter last name: "));
	contact.setNickname(getAlphaInput("Enter nickname: "));
	contact.setPhoneNumber(getNumInput("Enter phone number: "));
	contact.setSecret(getAlphaInput("Enter darkest secret: "));
	return contact;
}

void PhoneBook::add() {
	if (this->mContactCount == 8) {
		std::cout << "Phone book is full! Overwriting oldest items!" << std::endl;
		mContactCount = 0;
	}
	this->mContacts[mContactCount] = createContact();
	mContactCount++;
}

std::string truncateString(std::string str) {
	if (str.size() <= 10)
		return str;
	else
		return str.substr(0, 9) + '.';
}

void printContacts(Contact contacts[]) {
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; !contacts[i].getFirstName().empty(); i++) {
		std::cout.width(1);
		std::cout << "|";
		std::cout.width(10);
		std::cout << i;
		std::cout.width(1);
		std::cout << "|";
		std::cout.width(10);
		std::cout << truncateString(contacts[i].getFirstName());
		std::cout.width(1);
		std::cout << "|";
		std::cout.width(10);
		std::cout << truncateString(contacts[i].getLastName());
		std::cout.width(1);
		std::cout << "|";
		std::cout.width(10);
		std::cout << truncateString(contacts[i].getNickname());
		std::cout.width(1);
		std::cout << "|" << std::endl;
	}
}

void printDetails(Contact contact) {
	if (contact.getFirstName().empty())
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getSecret() << std::endl;
}

void PhoneBook::search() {
	std::string index;
	printContacts(this->mContacts);
	std::cout << "Pick index you want to see: ";
	getline(std::cin, index);
	if (isStringNumeric(index))
		printDetails(this->mContacts[std::stoi(index)]);
	else
		std::cout << "It is not a number!" << std::endl;
}

void PhoneBook::exit() {
	std::cout << "Thank you for using PhoneBook. See you next time!" << std::endl;
	::exit(0);
}