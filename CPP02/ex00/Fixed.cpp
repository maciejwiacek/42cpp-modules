#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractBits = 8;

Fixed::Fixed(): _numValue(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed): _numValue(fixed._numValue) {
	std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called\n";
	if (this != &copy) {
		this->_numValue = copy._numValue;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() {
	std::cout << "getRawBits member function called\n";
	return this->_numValue;
}

void Fixed::setRawBits(const int raw) {
	this->_numValue = raw;
}