#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
	std::cout << "WrongCat default constructor called\n";
	this->_type = "wrong-cat";
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal() {
	std::cout << "WrongCat copy constructor called\n";
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat assignment operator called\n";
	if (this != &other)
		this->_type = other._type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() {
	std::cout << "Meow\n";
}