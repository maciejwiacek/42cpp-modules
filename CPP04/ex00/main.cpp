#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "----------   TESTING ANIMALS   ----------\n\n";
	std::cout << "------    Constructing    ------\n";
	Animal *a = new Animal();
	Animal *d = new Dog();
	Animal *c = new Cat();

	std::cout << "\n------    Testing    ------\n";
	std::cout << a->getType() << " makes sound:\n";
	a->makeSound();
	std::cout << d->getType() << " makes sound:\n";
	d->makeSound();
	std::cout << c->getType() << " makes sound:\n";
	c->makeSound();

	std::cout << "\n------    Destructing    ------\n";
	delete a;
	delete d;
	delete c;

	std::cout << "\n\n----------   TESTING WRONG ANIMALS   ----------\n\n";
	std::cout << "------    Constructing    ------\n";
	WrongAnimal *wa = new WrongAnimal();
	WrongAnimal *wc = new WrongCat();

	std::cout << "\n------    Testing    ------\n";
	std::cout << wa->getType() << " makes sound:\n";
	wa->makeSound();
	std::cout << wc->getType() << " makes sound:\n";
	wc->makeSound();

	std::cout << "\n------    Destructing    ------\n";
	delete wa;
	delete wc;
}