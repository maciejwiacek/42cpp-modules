#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
private:
	Brain* _brain;
public:
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& other);
	virtual ~Cat();
	void makeSound();
	void setIdea(int i, std::string idea);
	void getIdeas();
};