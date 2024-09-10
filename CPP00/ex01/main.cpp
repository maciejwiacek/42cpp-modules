#include "PhoneBook/PhoneBook.hpp"

int main(void) {
	PhoneBook phoneBook;
	std::string command;

	std::cout << "---> PhoneBook <---" << std::endl;
	while (1) {
		std::cout << "Choose a command: ADD, SEARCH, EXIT: ";
		std::getline(std::cin, command);
		if (command == "ADD") {
			phoneBook.add();
		} else if (command == "SEARCH") {
			phoneBook.search();
		} else if (command == "EXIT") {
			phoneBook.exit();
		} else {
			std::cout << command << " is not a valid command!" << std::endl;
		}
	}
	return 0;
}