#include "Classes.hpp"

Base::~Base() { }

Base* generate(void) {
	srand(time(0));
	int random = rand() % 3;

	switch (random) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	return nullptr;
}

void identify(Base* p) {
	std::cout << "Identified class: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Unknown";
	std::cout << std::endl;
}

void identify(Base& p) {
	std::cout << "Identified class: ";

	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	} catch (...) { }

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch (...) { }

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch (...) { }

	std::cout << "Unknown\n";
}
