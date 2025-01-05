#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45),
	_target("target") {
	std::cout << GREEN << "RobotomyRequestForm default constructor called\n" << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45),
	_target(target) {
	std::cout << GREEN << "RobotomyRequestForm " << this->_name << " was created\n" << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other._name, other._signGrade, other._execGrade),
	_target(other._target) {
	std::cout << GREEN << "RobotomyRequestForm copy constructor called\n" << RESET;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << GREEN << "RobotomyRequestForm assignment constructor called\n" << RESET;
	if (this != &other)
		this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << RED << "ShrubberyCreationForm destructor called\n" << RESET;
}

const std::string RobotomyRequestForm::getTarget() {
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat &b) const {
	if (b.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	else if (!this->_isSigned)
		throw FormNotSignedException();

	static int robotomizedTracker = 0;

	std::cout << "<SOME DRILLING NOISES>\n";
	if (robotomizedTracker++ % 2)
		std::cout << this->_target << " has been robotomized successfully\n";
	else
		std::cout << this->_target << " hasn't been robotomized\n";
}