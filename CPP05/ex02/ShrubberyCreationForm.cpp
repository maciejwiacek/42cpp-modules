#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137),
	_target("target") {
	std::cout << GREEN << "ShrubberyCreationForm default constructor called\n" << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137),
	_target(target) {
	std::cout << GREEN << "ShrubberyCreationForm " << this->_name << " was created\n" << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other._name, other._signGrade, other._execGrade)
	, _target(other._target) {
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called\n" << RESET;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << GREEN << "ShrubberyCreationForm assignment constructor called\n" << RESET;
	if (this != &other)
		this->_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << RED << "ShrubberyCreationForm destructor called\n" << RESET;
}

const std::string ShrubberyCreationForm::getTarget() {
	return this->_target;
}

void printTree(std::ofstream& outfile) {
	outfile << "       ^\n";
	outfile << "      ^^^\n";
	outfile << "     ^^^^^\n";
	outfile << "    ^^^^^^^\n";
	outfile << "   ^^^^^^^^^\n";
	outfile << "  ^^^^^^^^^^^\n";
	outfile << "       ||\n";
	outfile << "       ||\n";
}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const {
	if (b.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	else if (!this->_isSigned)
		throw FormNotSignedException();

	std::ofstream outfile;
	outfile.open((this->_target + "_shrubbery").c_str());
	for (int i = 0; i < 5; i++)
		printTree(outfile);
	outfile.close();
}