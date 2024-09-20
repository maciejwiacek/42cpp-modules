#pragma once

#include <iostream>

class WrongAnimal {
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();
	void makeSound();
	std::string getType();
};