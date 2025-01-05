#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// Creating
	std::cout << YELLOW << "---------- CREATING ----------\n\n" << RESET;

	std::cout << BLUE << "Creating Bureaucrats\n" << RESET;
	Bureaucrat a = Bureaucrat("High grade", 1);
	Bureaucrat b = Bureaucrat("Low grade", 150);

	std::cout << BLUE << "Creating Forms\n" << RESET;
	Form f = Form("High requirements", 1, 1);
	Form g = Form("Low requirements", 150, 150);

	// Testing
	std::cout << YELLOW << "\n---------- TESTING ----------\n\n" << RESET;

	std::cout << BLUE << "Printing Bureaucrats\n" << RESET;
	std::cout << a;
	std::cout << b;

	std::cout << BLUE << "Printing Forms\n" << RESET;
	std::cout << f;
	std::cout << g;

	std::cout << BLUE << "beSigned\n" << RESET;
	try {
		f.beSigned(a);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	try {
		f.beSigned(b);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	std::cout << BLUE << "signForm\n" << RESET;
	try {
		b.signForm(f);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	try {
		b.signForm(g);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	//Destructing
	std::cout << YELLOW << "\n\n---------- DESTRUCTING ----------\n\n" << RESET;
}