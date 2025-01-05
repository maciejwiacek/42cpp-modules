#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"), _isSigned(false),
	_signGrade(150), _execGrade(150) {
	std::cout << "Form default constructor called\n";
}

AForm::AForm(const std::string &name, size_t signGrade, size_t execGrade)
		: _name(name), _isSigned(false),
		  _signGrade(signGrade), _execGrade(execGrade) {
	std::cout << GREEN << "Form " << this->_name << " constructor called\n" << RESET;
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned),
	_signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << GREEN << "Form copy constructor called\n" << RESET;
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	std::cout << GREEN << "Form assignment constructor called\n" << RESET;
	return *this;
}

AForm::~AForm() {
	std::cout << RED << "Form destructor called\n" << RESET;
}

const std::string AForm::getName() {
	return this->_name;
}

bool AForm::getIsSigned() {
	return this->_isSigned;
}

size_t AForm::getSignGrade() {
	return this->_signGrade;
}

size_t AForm::getExecGrade() {
	return this->_execGrade;
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->_signGrade) {
		this->_isSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

void AForm::execute(const Bureaucrat &b) const {
	(void)b;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low\n";
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high\n";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed\n";
}

std::ostream& operator<<(std::ostream& os, AForm& f) {
	os << f.getName() << " is " << std::boolalpha << f.getIsSigned() << std::endl;
	return os;
}