#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"), _isSigned(false),
	_signGrade(150), _execGrade(150) {
	std::cout << "Form default constructor called\n";
}

Form::Form(const std::string &name, size_t signGrade, size_t execGrade)
	: _name(name), _isSigned(false),
	_signGrade(signGrade), _execGrade(execGrade) {
	std::cout << GREEN << "Form " << this->_name << " constructor called\n" << RESET;
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned),
	_signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << GREEN << "Form copy constructor called\n" << RESET;
}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	std::cout << GREEN << "Form assignment constructor called\n" << RESET;
	return *this;
}

Form::~Form() {
	std::cout << RED << "Form destructor called\n" << RESET;
}

const std::string Form::getName() {
	return this->_name;
}

bool Form::getIsSigned() {
	return this->_isSigned;
}

size_t Form::getSignGrade() {
	return this->_signGrade;
}

size_t Form::getExecGrade() {
	return this->_execGrade;
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->_signGrade) {
		this->_isSigned = true;
	} else {
		throw Bureaucrat::GradeTooLowException();
	}
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low\n";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high\n";
}

std::ostream& operator<<(std::ostream& os, Form& f) {
	os << f.getName() << " is " << std::boolalpha << f.getIsSigned() << std::endl;
	return os;
}