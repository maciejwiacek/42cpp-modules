#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {
	std::cout << GREEN << "Bureaucrat default constructor called\n" << RESET;
}

Bureaucrat::Bureaucrat(const std::string name, size_t grade): _name(name) {
	std::cout << GREEN << "Bureaucrat constructor called with name " << this->_name << std::endl << RESET;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	std::cout << GREEN << "Bureaucrat copy constructor called\n" << RESET;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << GREEN << "Bureaucrat assignment operator called\n" << RESET;
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "Bureaucrat destructor called\n" << RESET;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

size_t Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::setGrade(size_t grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &f) {
	if (f.getIsSigned())
	{
		std::cout << this->_name << " couldn't sign " << f.getName()
		<< " because it is already signed\n";
	} else if (f.getSignGrade() < this->_grade)
	{
		std::cout << this->_name << " couldn't sign " << f.getName()
		<< " because his grade is too low\n";
	} else {
		std::cout << this->_name << " signed " << f.getName() << std::endl;
		f.beSigned(*this);
	}
}

void Bureaucrat::executeForm(const AForm &form) {
	form.execute(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low\n";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << (!bureaucrat.getName().empty() ? bureaucrat.getName() : "<Undefined>") << ", bureaucrat grade "
	<< bureaucrat.getGrade() << std::endl;
	return os;
}