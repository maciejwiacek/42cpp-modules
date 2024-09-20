#include "Cat.hpp"

Cat::Cat(): Animal() {
	std::cout << "Cat default constructor called\n";
	this->_type = "cat";
}

Cat::Cat(const Cat &copy): Animal() {
	std::cout << "Cat copy constructor called\n";
	*this = copy;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignment operator called\n";
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound() {
	std::cout << "Meow\n";
}