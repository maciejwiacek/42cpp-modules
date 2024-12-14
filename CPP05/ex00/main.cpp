#include "Bureaucrat.hpp"

int main() {
	Bureaucrat a = Bureaucrat("Grzegorz", 1);
	Bureaucrat b = a;
	try {
		a.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	try {
		a.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << a;
	std::cout << b;
}