#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _numValue;
	static const int _fractBits;
public:
	Fixed(); // Default constructor
	Fixed(const Fixed& fixed); // Copy constructor
	Fixed& operator = (const Fixed& copy); // Copy assignment operator overload
	~Fixed(); // Destructor

	int getRawBits(void); // Getter
	void setRawBits(int const raw); // Setter
};

#endif