#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern &other) {
	(void)other;
	std::cout << GREEN << "Intern copy constructor called\n" << RESET;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	std::cout << GREEN << "Intern assignment constructor called\n" << RESET;
	return *this;
}

Intern::~Intern() {
	std::cout << RED << "Intern destructor called\n" << RESET;
}

// Make form

AForm* createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
	std::string names[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *(*creatingFuncs[])(std::string) = {createRobotomy, createPresidential, createShrubbery};

	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << names[i] << std::endl;
			return creatingFuncs[i](target);
		}
	}

	return NULL;
}
