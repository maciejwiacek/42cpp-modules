#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	// Creating
	std::cout << YELLOW << "---------- CREATING ----------\n\n" << RESET;

	std::cout << BLUE << "Creating Bureaucrat\n" << RESET;
	Bureaucrat* makumba = new Bureaucrat("Makumba", 150);

	std::cout << BLUE << "Creating Forms\n" << RESET;
	PresidentialPardonForm* presidential;
	RobotomyRequestForm* robotomy;
	ShrubberyCreationForm* shrubbery;

	try {
		presidential = new PresidentialPardonForm("house");
	} catch (std::exception& e) {
		std::cout << e.what();
		delete makumba;
		return 1;
	}

	try {
		robotomy = new RobotomyRequestForm("garage");
	} catch (std::exception& e) {
		std::cout << e.what();
		delete makumba;
		delete presidential;
		return 1;
	}

	try {
		shrubbery = new ShrubberyCreationForm("balcony");
	} catch (std::exception& e) {
		std::cout << e.what();
		delete makumba;
		delete presidential;
		delete robotomy;
		return 1;
	}

	// Testing
	std::cout << YELLOW << "\n---------- TESTING ----------\n\n" << RESET;

	std::cout << BLUE << "Test Shrubbery\n" << RESET;
	try {
		makumba->signForm(*shrubbery);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	makumba->setGrade(145);
	try {
		makumba->signForm(*shrubbery);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	try {
		makumba->executeForm(*shrubbery);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	makumba->setGrade(137);
	try {
		makumba->executeForm(*shrubbery);
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	std::cout << BLUE << "Test Robotomy\n" << RESET;
	try {
		makumba->signForm(*robotomy);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	makumba->setGrade(72);
	try {
		makumba->signForm(*robotomy);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	try {
		makumba->executeForm(*robotomy);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	makumba->setGrade(45);
	try {
		makumba->executeForm(*robotomy);
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	std::cout << BLUE << "Test Presidential\n" << RESET;
	try {
		makumba->signForm(*presidential);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	makumba->setGrade(25);
	try {
		makumba->signForm(*presidential);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	try {
		makumba->executeForm(*presidential);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	makumba->setGrade(5);
	try {
		makumba->executeForm(*presidential);
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	//Destructing
	std::cout << YELLOW << "\n\n---------- DESTRUCTING ----------\n\n" << RESET;

	delete makumba;
	delete presidential;
	delete robotomy;
	delete shrubbery;

	return 0;
}