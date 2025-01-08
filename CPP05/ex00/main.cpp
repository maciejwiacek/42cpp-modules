#include "Bureaucrat.hpp"

template <typename T>
void safeCall(T& instance, void(T::*func)())
{
	try {
		(instance.*func)();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
}

int main() {
	std::cout << YELLOW << "---------- CREATING ----------\n\n" << RESET;

	std::cout << BLUE << "Creating Bureaucrat\n" << RESET;
	Bureaucrat* makumba;
	try {
		makumba = new Bureaucrat("Makumba", 1);
	} catch (std::exception& e) {
		std::cout << e.what();
		return 1;
	}

	std::cout << YELLOW << "\n---------- TESTING ----------\n\n" << RESET;
	std::cout << BLUE << "Increment failure | Decrement success\n" << RESET;
	safeCall(*makumba, &Bureaucrat::incrementGrade);
	safeCall(*makumba, &Bureaucrat::decrementGrade);

	std::cout << BLUE << "Decrement failure | Increment success\n" << RESET;
	makumba->setGrade(150);
	safeCall(*makumba, &Bureaucrat::decrementGrade);
	safeCall(*makumba, &Bureaucrat::incrementGrade);

	std::cout << BLUE << "Print info with operator overload\n" << RESET;
	std::cout << *makumba;

	std::cout << YELLOW << "\n\n---------- DESTRUCTING ----------\n\n" << RESET;

	delete makumba;
}
