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
	int getRawBits(void);
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif