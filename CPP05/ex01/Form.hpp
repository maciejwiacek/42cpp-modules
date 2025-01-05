#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <sstream>

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool _isSigned;
		size_t const _signGrade;
		size_t const _execGrade;

	public:
		// Initializers
		Form();
		Form(const std::string& name, size_t signGrade, size_t execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		// Getters
		std::string const getName();
		bool getIsSigned();
		size_t getSignGrade();
		size_t getExecGrade();
		// Manipulation
		void beSigned(const Bureaucrat& b);
		// Exceptions
		class GradeTooLowException : public std::exception {
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Form& f);