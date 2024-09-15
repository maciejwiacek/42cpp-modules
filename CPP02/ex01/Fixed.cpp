#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed(): _numValue(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int intNum) {
	std::cout << "Int constructor called\n";
	this->_numValue = intNum << this->_fractBits;
}

Fixed::Fixed(const float floatNum) {
	std::cout << "Float constructor called\n";
	this->_numValue = roundf(floatNum * (1 << this->_fractBits));
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

float Fixed::toFloat() const {
	return static_cast<float>(this->_numValue) / (1 << this->_fractBits);
}

int Fixed::toInt() const {
	return roundf(this->_numValue / (1 << this->_fractBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}