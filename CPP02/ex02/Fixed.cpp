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

// Get/set
int Fixed::getRawBits() {
	std::cout << "getRawBits member function called\n";
	return this->_numValue;
}

void Fixed::setRawBits(const int raw) {
	this->_numValue = raw;
}

// Conversion
float Fixed::toFloat() const {
	return static_cast<float>(this->_numValue / pow(2, this->_fractBits));
}

int Fixed::toInt() const {
	return static_cast<int>(this->_numValue / pow(2, this->_fractBits));
}

// Max/min
const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2) {
	return (num1 < num2 ? num1 : num2);
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2) {
	return (num1 > num2 ? num1 : num2);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2) {
	return (num1 < num2 ? num1 : num2);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2) {
	return (num1 > num2 ? num1 : num2);
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
	return this->_numValue > other._numValue;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_numValue < other._numValue;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_numValue >= other._numValue;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_numValue <= other._numValue;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_numValue == other._numValue;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_numValue != other._numValue;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

// Increment/decrement operators

Fixed Fixed::operator++() {
	this->_numValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++(*this);
	return tmp;
}

Fixed Fixed::operator--() {
	this->_numValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	++(*this);
	return tmp;
}

// Input operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}