#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5),
	_target("target") {
	std::cout << GREEN << "PresidentialPardonForm default constructor called\n" << RESET;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5),
	_target(target) {
	std::cout << GREEN << "PresidentialPardonForm " << this->_target << " was created\n" << RESET;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other._name, other._signGrade, other._execGrade),
	_target(other._target) {
	std::cout << GREEN << "PresidentialPardonForm copy constructor called\n" << RESET;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << GREEN << "PresidentialPardonForm assignment constructor called\n" << RESET;
	if (this != &other)
		this->_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << RED << "PresidentialPardonForm destructor called\n" << RESET;
}

const std::string PresidentialPardonForm::getTarget() {
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat &b) const {
	if (b.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	else if (!this->_isSigned)
		throw FormNotSignedException();

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox\n";
}