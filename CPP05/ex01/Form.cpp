#include "Form.hpp"

// Initializers

Form::Form(): _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << GREEN << "Form default initializer called\n" << RESET;
}

Form::Form(const std::string name, const size_t gradeToSign, const size_t gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << GREEN << "Form named " << this->_name << " was successfully created\n" << RESET;
}

Form::Form(const Form &copy): _name(copy.getName()), _isSigned(false), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute()) {
	std::cout << GREEN << "Form copy constructor called\n" << RESET;
}

Form &Form::operator=(const Form &other) {
	std::cout << GREEN << "Form assignment constructor called\n" << RESET;
	if (this != &other)
		return *this;
	return *this;
}

Form::~Form() {
	std::cout << RED << "Form destructor called\n" << RESET;
}

// Getters

std::string Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() {
	return this->_isSigned;
}

size_t Form::getGradeToSign() const {
	return this->_gradeToSign;
}

size_t Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

// Form Manipulation

void Form::beSigned(Bureaucrat &b) {
	if (this->_isSigned)
		throw FormAlreadySignedException();
	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

// Exceptions

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!\n";
}

const char *Form::FormAlreadySignedException::what() const throw() {
	return "Form is already signed!\n";
}
