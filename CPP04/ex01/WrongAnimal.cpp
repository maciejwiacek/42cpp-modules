#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("wrong-animal") {
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "WrongAnimal copy constructor called\n";
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "WrongAnimal assignment operator called\n";
	if (this != &other)
		this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound() {
	std::cout << "WrongAnimal sound\n";
}

std::string WrongAnimal::getType() {
	return this->_type;
}