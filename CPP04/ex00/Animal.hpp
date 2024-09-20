#pragma once

#include <iostream>

class Animal {
protected:
	std::string _type;
public:
	Animal();
	Animal(const Animal& copy);
	Animal& operator=(const Animal& other);
	virtual ~Animal();
	virtual void makeSound();
	std::string getType();
};