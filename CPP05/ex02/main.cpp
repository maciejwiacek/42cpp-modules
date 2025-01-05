#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	// Creating
	std::cout << YELLOW << "---------- CREATING ----------\n\n" << RESET;

	std::cout << BLUE << "Creating Bureaucrats\n" << RESET;
	Bureaucrat a = Bureaucrat("Warren", 1);

	std::cout << BLUE << "Creating Forms\n" << RESET;
	ShrubberyCreationForm s = ShrubberyCreationForm("target");
	RobotomyRequestForm r = RobotomyRequestForm("target");
	PresidentialPardonForm p = PresidentialPardonForm("target");

	// Testing
	std::cout << YELLOW << "\n---------- TESTING ----------\n\n" << RESET;

	a.signForm(s);
	a.signForm(r);
	a.signForm(p);
	s.execute(a);
	r.execute(a);
	p.execute(a);

	//Destructing
	std::cout << YELLOW << "\n\n---------- DESTRUCTING ----------\n\n" << RESET;
}