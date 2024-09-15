#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _numValue;
	static const int _fractBits;
public:
	Fixed();
	Fixed(const int intNum);
	Fixed(const float floatNum);
	Fixed(const Fixed& fixed);
	Fixed& operator = (const Fixed& copy);
	~Fixed();
	// Get/met
	int getRawBits(void);
	void setRawBits(int const raw);
	// Conversion
	float toFloat(void) const;
	int toInt(void) const;
	// Max/min
	static const Fixed& min(const Fixed& num1, const Fixed& num2);
	static Fixed& min(Fixed& num1, Fixed& num2);
	static const Fixed& max(const Fixed& num1, const Fixed& num2);
	static Fixed& max(Fixed& num1, Fixed& num2);
	// Comparison operators
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Increment/decrement operators
	Fixed operator++(void);
	Fixed operator++(int);
	Fixed operator--(void);
	Fixed operator--(int);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif