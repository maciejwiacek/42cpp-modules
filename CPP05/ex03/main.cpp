#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	// Creating
	std::cout << YELLOW << "---------- CREATING ----------\n\n" << RESET;

	std::cout << BLUE << "Creating Bureaucrat\n" << RESET;
	Bureaucrat* makumba = new Bureaucrat("Makumba", 1);

	std::cout << BLUE << "Creating Intern\n" << RESET;
	Intern kid = Intern();

	// Testing
	std::cout << YELLOW << "\n---------- TESTING ----------\n\n" << RESET;

	std::cout << BLUE << "\nTest Robotomy\n" << RESET;
	AForm* rrf;
	rrf = kid.makeForm("robotomy request", "Bender");
	makumba->signForm(*rrf);
	makumba->executeForm(*rrf);

	std::cout << BLUE << "\nTest Shrubbery\n" << RESET;
	AForm* scf;
	scf = kid.makeForm("shrubbery creation", "Bender");
	makumba->signForm(*scf);
	makumba->executeForm(*scf);

	std::cout << BLUE << "\nTest Presidential\n" << RESET;
	AForm* ppf;
	ppf = kid.makeForm("presidential pardon", "Bender");
	makumba->signForm(*ppf);
	makumba->executeForm(*ppf);

	//Destructing
	std::cout << YELLOW << "\n\n---------- DESTRUCTING ----------\n\n" << RESET;

	delete makumba;
	delete rrf;
	delete scf;
	delete ppf;

	return 0;
}