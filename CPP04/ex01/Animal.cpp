#include "Animal.hpp"

Animal::Animal(): _type("animal") {
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy constructor called\n";
	*this = copy;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal assignment operator called\n";
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called\n";
}

void Animal::makeSound() {
	std::cout << "Default animal sound\n";
}

std::string Animal::getType() {
	return this->_type;
}