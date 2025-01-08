#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	// Creating
	std::cout << YELLOW << "---------- CREATING ----------\n\n" << RESET;

	std::cout << BLUE << "Creating Bureaucrat\n" << RESET;
	Bureaucrat* makumba = new Bureaucrat("Makumba", 150);

	std::cout << BLUE << "Creating Forms\n" << RESET;
	Form* formularz;
	Form* form;

	try {
		formularz = new Form("formularz mieszkaniowy", 1, 1);
	} catch (std::exception& e) {
		std::cout << e.what();
		return 1;
	}

	try {
		form = new Form("formularz reklamacyjny", 1, 1);
	} catch (std::exception& e) {
		std::cout << e.what();
		delete formularz;
		return 1;
	}

	// Testing
	std::cout << YELLOW << "\n---------- TESTING ----------\n\n" << RESET;

	std::cout << BLUE << "Try signing form, grade too low\n" << RESET;
	try {
		formularz->beSigned(*makumba);
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	std::cout << BLUE << "Sign a form using beSigned\n" << RESET;
	makumba->setGrade(1);
	std::cout << "Form sign status: " << std::boolalpha << formularz->getIsSigned() << std::endl;
	formularz->beSigned(*makumba);
	std::cout << "Form sign status: " << std::boolalpha << formularz->getIsSigned() << std::endl;

	std::cout << BLUE << "Sign a form using signForm\n" << RESET;
	std::cout << "Form sign status: " << std::boolalpha << form->getIsSigned() << std::endl;
	makumba->setGrade(1);
	try {
		makumba->signForm(*form);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << "Form sign status: " << std::boolalpha << form->getIsSigned() << std::endl;

	//Destructing
	std::cout << YELLOW << "\n\n---------- DESTRUCTING ----------\n\n" << RESET;

	delete makumba;
	delete formularz;
	delete form;
}