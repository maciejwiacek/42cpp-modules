#include "Cat.hpp"
#include "Dog.hpp"
#include "Colors.hpp"

int main() {
	std::cout << BLUE << "----- CONSTRUCTING ANIMALS -----\n" << RESET;
	Animal* animals[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << GREEN << "\n----- TESTING ANIMALS -----\n" << RESET;
	for (int i = 0; i < 10; i++) {
		std::cout << "Animal type " << animals[i]->getType() << " makes sound -> " << RED;
		animals[i]->makeSound();
		std::cout << RESET;
	}

	std::cout << BLUE << "\n----- DESTRUCTING ANIMALS -----\n" << RESET;
	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}

	std::cout << BLUE << "----- CONSTRUCTING COPIES -----\n" << RESET;
	Cat *c = new Cat();
	c->setIdea(0, "Some idea");
	c->setIdea(1, "Another idea");
	c->setIdea(2, "One more idea");
	c->setIdea(17, "Some unordered idea");
	c->setIdea(101, "Out of range idea");
	Cat *cc = new Cat(*c);
	std::cout << c->getType() << " named c has following ideas:\n";
	c->getIdeas();
	std::cout << RED << "DESTRUCTING CAT C\n" << RESET;
	delete c;
	std::cout << RED << "-------------------------------------------------------\n" << RESET;
	std::cout << cc->getType() << " named cc has following ideas:\n";
	cc->getIdeas();
	std::cout << RED << "DESTRUCTING CAT CC\n" << RESET;
	delete cc;
	std::cout << RED << "-------------------------------------------------------\n" << RESET;

//	std::cout << BLUE << "----- SHOULD FAIL -----\n" << RESET;
//	Animal *a = new Animal();
//	a->makeSound();
//	delete a;
}