#include "Dog.hpp"

Dog::Dog(): Animal() {
	std::cout << "Dog default constructor called\n";
	this->_type = "dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &copy): Animal() {
	std::cout << "Dog copy constructor called\n";
	*this = copy;
}

Dog Dog::operator=(const Dog &other) {
	std::cout << "Dog assignment operator called\n";
	if (this != &other)
	{
		this->_type = other._type;
		this->_brain = other._brain;
	}
	return *this;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound() {
	std::cout << "Woof! Woof!\n";
}