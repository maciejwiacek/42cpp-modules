#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	delete d;
	delete c;
}